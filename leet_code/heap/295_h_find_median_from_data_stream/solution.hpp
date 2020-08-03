/*
https://leetcode.com/problems/find-median-from-data-stream/
*/

#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using std::vector;

// TODO:
//  describe solution
//  implement follow-up question

namespace V1 {
/*
 * */
class MedianFinder {
private:
    std::priority_queue< int > m_lo;
    std::priority_queue< int, std::vector< int >, std::greater< int >> m_hi;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        m_lo.push( num );

        m_hi.push( m_lo.top() );

        m_lo.pop();

        if( m_lo.size() < m_hi.size() ) {
            m_lo.push( m_hi.top() );
            m_hi.pop();
        }
    }

    double findMedian() {
        if( m_lo.size() == m_hi.size() )
            return static_cast< double  >( m_lo.top() + m_hi.top() ) / 2;
        else
            return m_lo.top();
    }
};
} // namespace V1


namespace V2 {
/* LC: Time Limit Exceeded
 *
 * Idea is using QuickSelect
 *
 * QuickSelect: Time O(N), Space (1)
 *
 * N - current number of elements
 * Time O(N), find median using QuickSelect
 * Space (N), store all elements
 * */
class MedianFinder {

    using Elements = std::vector< int >;

    Elements m_elements;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        m_elements.push_back( num );
    }

    double findMedian() {
        const int size = m_elements.size();
        if( size & 1 ) {
            nth_element( m_elements, size / 2 );
            return m_elements[ size / 2 ];
        }
        else {
            nth_element( m_elements, size / 2 - 1 );
            double val1 = m_elements[ size / 2 - 1 ];
            nth_element( m_elements, size / 2 );
            double val2 = m_elements[ size / 2 ];

            return ( val1 + val2 ) / 2;
        }
    }

private:
    void nth_element( Elements& elements, int pos ) {
        if( elements.size() <= 1 )
            return;

        int left = 0;
        int right = elements.size() - 1;
        while( true ) {
            int pivotIdx = right;
            int finalChosenIdx = partition( elements, left, right, pivotIdx );

            if( finalChosenIdx == pos )
                break;

            if( finalChosenIdx < pos )
                left = finalChosenIdx + 1;
            else
                right = finalChosenIdx - 1;
        }
    }

    int partition( Elements& elements, int left, int right, int pivotIdx ) {
        int pivotValue = elements[ pivotIdx ];
        std::swap( elements[ right ], elements[ pivotIdx ] );

        int lesserItemsEndIdx = left;
        for( int i = left; i < right; ++i ) {
            if( elements[ i ] < pivotValue ) {
                std::swap( elements[ i ], elements[ lesserItemsEndIdx ] );
                ++lesserItemsEndIdx;
            }
        }

        std::swap( elements[ right ], elements[ lesserItemsEndIdx ] );

        return lesserItemsEndIdx;
    }
};
} // namespace V2
