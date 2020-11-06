/*
https://leetcode.com/problems/lfu-cache/
*/

#include <unordered_map>
#include <memory>

namespace {
/*
N - capacity

Time O(1) - get, put
Space O(N)
*/
class LFUCache {
    class List {
        public:
            class Node {
                friend class List;
            public:
                using UPtr = std::unique_ptr< Node >;

                int key{ 0 };
                int value{ 0 };
                int freq{ 0 };

                Node() = default;

                Node( int key, int value, int freq = 1 )
                :   key{ key }
                ,   value{ value }
                ,   freq{ freq }
                {}

            private:
                Node* prev{ nullptr };
                Node* next{ nullptr };
            }; // class Node

            List()
            :   head{ std::make_unique< Node >() }
            ,   tail{ std::make_unique< Node >() }
            {
                head->next = tail.get();
                tail->prev = head.get();
            }

            bool isEmpty() const {
                return head->next == tail.get();
            }

            Node* popBack() {
                auto node = tail->prev;

                pop( node );

                return node;
            }

            void pop( Node* node ) {
                node->prev->next = node->next;
                node->next->prev = node->prev;

                node->next = node->prev = nullptr;
            }

            void pushFront( Node* node ) {
                node->next = head->next;
                node->prev = head.get();

                head->next->prev = node;
                head->next = node;
            }
            
            

        private:
            Node::UPtr head;
            Node::UPtr tail;
    }; // class List

public:
    LFUCache(int capacity)
    :   capacity{ capacity }
    ,   minFrequency{ 0 }
    {
    }

    int get(int key) {
        auto it = keyToNode.find( key );
        if( it == keyToNode.end() )
            return -1;

        updateNode( it->second.get() );
        return it->second->value;
    }

    void put(int key, int value) {
        if( capacity == 0 )
            return;

        auto it = keyToNode.find( key );
        if( it == keyToNode.end() ) {
            if( keyToNode.size() == capacity ) {
                auto node = freqToList[ minFrequency ].popBack();
                 if( freqToList[ minFrequency ].isEmpty() )
                    freqToList.erase( minFrequency );

                keyToNode.erase( node->key );
            }

            minFrequency = 1;
            auto [it,_] = keyToNode.try_emplace( key, std::make_unique< List::Node >( key, value ) );
            freqToList[ minFrequency ].pushFront( it->second.get() );
        }
        else {
            it->second->value = value;
            updateNode( it->second.get() );
        }
    }

private:
    void updateNode( List::Node* node ) {
        int frequency = node->freq;
        freqToList[ frequency ].pop( node );

        if( minFrequency == frequency && freqToList[ frequency ].isEmpty() ) {
            minFrequency += 1;
        }
        if( freqToList[ frequency ].isEmpty() ) {
            freqToList.erase( frequency );
        }

        frequency += 1;
        node->freq = frequency;
        freqToList[ frequency ].pushFront( node );
    }

private:
    const int capacity;
    int minFrequency;
    std::unordered_map< int, List::Node::UPtr > keyToNode;
    std::unordered_map< int, List > freqToList;
}; // class LFUCache
} //namespace
