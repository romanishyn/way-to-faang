/*
https://leetcode.com/problems/moving-average-from-data-stream/
*/

#include <queue>

namespace {
/*
Double-ended Queue

N - size of windwo

Time O(1)
Space O(N)
*/
class MovingAverage {
    std::queue< int > m_window;
    double m_totalSum{ 0 };
    const int m_windowSize;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
        :   m_windowSize{ size } {
        
    }

    double next(int val) {
        m_totalSum += val;
        m_window.push( val );
        if( m_window.size() > m_windowSize ) {
            int lastValue = m_window.front();
            m_window.pop();
            m_totalSum -= lastValue;
        }

        return m_totalSum / m_window.size();
    }
};
} // namespace

namespace {
/*
Fixed size queue.

N - size of window

Time O(1)
Space O(N)
*/

class Queue {
    std::vector< int > m_queue;
    int m_beginIdx;
    int m_endIdx;

public:
    Queue( int size )
        : m_queue( size + 1 )
        , m_beginIdx( 0 )
        , m_endIdx( 0 )
        {}

    int pop() {
        assert( ! empty() )

        m_beginIdx = nextIdx( m_beginIdx );
    }

    int push( int value ) {
        assert( ! full() );

        m_queue[ m_endIdx ] = value;
        m_endIdx = nextIdx( m_endIdx );
    }

    bool full() const {
        return size() == m_queue.size() - 1;
    }

    bool empty() const {
        return size() == 0;
    }

    int size() const {
        if( m_beginIdx <= m_endIdx )
            return m_endIdx - m_beginIdx;
        else
            return m_endIdx + m_queue.size() - m_beginIdx;
    }

    int front() const {
        assert( ! empty() );
        return m_queue[ m_beginIdx ];
    }

private:
    int nextIdx( int idx ) const {
        ++idx;
        if( idx == m_queue.size() )
            idx = 0;

        return idx;
    }
};
class MovingAverage {
    Queue m_queue;
    double m_windowSum{ 0 };

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    :   m_queue( size ) {
        
    }

    double next(int val) {
        m_windowSum += val;

        if( m_queue.full() ) {
            m_windowSum -= m_queue.front();
            m_queue.pop();
        }

        m_queue.push( val );

        return m_windowSum / m_queue.size();
    }
};
} // namespace

namespace {
/*
Fixed size queue.

N - size of window

Time O(1)
Space O(N)
*/
class MovingAverage {
    std::vector< int > m_window;
    int m_counter = 0;
    int m_head{ 0 };
    double m_windowSum{ 0 };
    

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    :   m_window( size ){
        
    }

    double next(int val) {
        ++m_counter;

        int tail = ( m_head + 1 ) % m_window.size();

        m_windowSum += val - m_window[ tail ];

        return m_windowSum / std::min( m_counter, m_window.size() );
    }
};
} // namespace