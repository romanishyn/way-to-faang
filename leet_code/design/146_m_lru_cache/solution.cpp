/*
https://leetcode.com/problems/lru-cache/
*/

#include <unordered_map>
#include <list>
#include <memory>

namespace {
/*
N - capacity

Time O(1) - get, put
Space O(N)
*/
class LRUCache {
    using List = std::list< int >; // key
    List list;
    std::unordered_map< int, std::pair< int/*val*/, List::iterator > > cache;
    const int capacity;

public:
    LRUCache(int capacity)
    :   capacity{ capacity }
    {
        
    }

    int get(int key) {
        auto it = cache.find( key );
        if( it == cache.end() )
            return -1;

        list.erase( it->second.second );
        list.push_front( it->first );
        it->second.second = list.begin();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find( key );
        if( it == cache.end() ) {
            list.push_front( key );
            cache.try_emplace( key, std::make_pair( value, list.begin() ) );
        }
        else {
            it->second.first = value;
            list.erase( it->second.second );
            list.push_front( it->first );
            it->second.second = list.begin();
        }

        if( cache.size() > capacity ) {
            cache.erase( list.back() );
            list.pop_back();
        }
    }
};
} //namespace

namespace {
/*
using new, delete

*/
class LRUCache {
    struct Node {
        Node* prev{ nullptr };
        Node* next{ nullptr };

        int key{ 0 };
        int value{ 0 };
    };

    Node head;
    Node tail;
    std::unordered_map< int, Node* > cache;
    const int capacity;

public:
    LRUCache(int capacity)
    :   capacity{ capacity }
    {
        head.next = &tail;
        tail.prev = &head;
    }

    int get(int key) {
        auto it = cache.find( key );
        if( it == cache.end() )
            return -1;

        moveToHead( it->second );
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache.find( key );
        if( it == cache.end() ) {
            auto node = new Node{ .key = key, .value = value };
            putToHead( node );
            cache.try_emplace( key, node );
        }
        else {
            moveToHead( it->second );
            it->second->value = value;
        }

        if( cache.size() > capacity ) {
            auto node = tail.prev;
            extractFromList( node );
            cache.erase( node->key );
            delete node;
        }
    }

private:
    void moveToHead( Node* node ) {
        extractFromList( node );
        putToHead( node );
    }

    void putToHead( Node* node ) {
        node->next = head.next;
        node->prev = &head;
        head.next->prev = node;
        head.next = node;
    }

    void extractFromList( Node* node ) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
} // namespace


namespace {
class LRUCache {
    struct Node {
        using UPtr = std::unique_ptr< Node >;

        Node* prev{ nullptr };
        Node* next{ nullptr };

        int key{ 0 };
        int value{ 0 };

        Node( int key, int value )
        :   key{ key }
        ,   value{ value }
            {}

        Node() = default;
    };

    Node::UPtr head;
    Node::UPtr tail;

    const int maxCapacity;
    std::unordered_map< int, Node::UPtr > cache;

public:
    LRUCache(int capacity)
    :   head{ std::make_unique< Node >() }
    ,   tail{ std::make_unique< Node >() }
    ,   maxCapacity{ capacity }
    {
        head->next = tail.get();
        tail->prev = head.get();
    }

    int get(int key) {
        auto it = cache.find( key );
        if( it == cache.end() )
            return -1;

        moveToHead( it->second.get() );
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache.find( key );

        if( it == cache.end() ) {
            auto node = std::make_unique< Node >( key, value );

            pushToHead( node.get() );

            cache.try_emplace( key, std::move( node ) );

            if( cache.size() > maxCapacity ) {
                removeLruEntry();
            }
        }
        else {
            it->second->value = value;
            moveToHead( it->second.get() );
        }
    }

private:
    void removeLruEntry() {
        auto node = tail->prev;
        extractFromList( node );
        cache.erase( node->key );
    }

    void moveToHead( Node* node ) {
        extractFromList( node );
        pushToHead( node );
    }

    void extractFromList(  Node* node ) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void pushToHead( Node* node ) {
        node->next = head->next;
        node->prev = head.get();

        head->next->prev = node;
        head->next = node;
    }
};
} // namespace