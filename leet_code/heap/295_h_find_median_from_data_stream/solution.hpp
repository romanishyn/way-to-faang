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
/*
 * */
} // namespace V2
