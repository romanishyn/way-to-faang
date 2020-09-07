/*
https://leetcode.com/problems/maximum-frequency-stack/
*/

#include <unordered_map>
#include <queue>
#include <stack>

namespace {
/*
Maintain hash map of number and frequency.
Maintain max heap of pushed values.

N - number of push calls

Time O(logN) - push and pop
Space O(N)
*/
class FreqStack {
    struct Number {
        int value;
        int frequency;
        int id;

        bool operator < ( const Number& rhs ) const {
            if( frequency == rhs.frequency )
                return id < rhs.id;
            else
                return frequency < rhs.frequency;
        }
    };

    std::unordered_map< int, int > numToFrequency;
    std::priority_queue< Number > maxHeap;

    int getId() {
        static int id = 0;
        return id++;
    }

public:
    FreqStack() {
        
    }

    void push(int x) {
        ++numToFrequency[ x ];
        Number number{
            x,
            numToFrequency[ x ],
            getId()
        };
        maxHeap.push( number );
    }

    int pop() {
        auto number = maxHeap.top();
        maxHeap.pop();
        --numToFrequency[ number.value ];
        return number.value;
    }
};
} // namespace

namespace {
/*
Stack of stacks

Time O(1) push, pop
Space O(N)
*/
class FreqStack {
    std::unordered_map< int, int > numToFrequency;
    std::unordered_map< int, std::stack< int > > groups;
    int maxFrequency{ 0 };

public:
    FreqStack() {
        
    }

    void push(int x) {
        ++numToFrequency[ x ];
        groups[ numToFrequency[ x ] ].push( x );
        maxFrequency = std::max( maxFrequency, numToFrequency[ x ] );
    }

    int pop() {
        int number = groups[ maxFrequency ].top();
        groups[ maxFrequency ].pop();
        if( groups[ maxFrequency ].empty() ) {
            groups.erase( maxFrequency );
            --maxFrequency;
        }
        if( --numToFrequency[ number ] == 0 )
            numToFrequency.erase( number );
        return number;
    }
};
} // namespace

namespace {
/*
Bucket sort

Time 
*/
class FreqStack {
    std::vector< std::stack< int > > buckets;
    std::unordered_map< int, int > numToFrequency;

public:
    FreqStack() {
        
    }

    void push(int x) {
        if( buckets.size() == numToFrequency[ x ] )
            buckets.push_back( {} );
        buckets[ numToFrequency[ x ] ].push( x );
        ++numToFrequency[ x ];
    }

    int pop() {
        int number = buckets.back().top();
        buckets.back().pop();
        if( buckets.back().empty() )
            buckets.pop_back();
        if( --numToFrequency[ number ] == 0 )
            numToFrequency.erase( number );

        return number;
    }
};
} // namespace
