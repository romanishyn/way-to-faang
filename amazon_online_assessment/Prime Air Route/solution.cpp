/*
https://leetcode.com/discuss/interview-question/373202
*/

#include<iostream>
#include<vector>
#include <cassert>

namespace {
/*
Naive solution

N - size of a
M - size of b

Time O(N*M) - stable time
Space O(1) if ignoring output result
*/
class PriveAirRoute {
public:
    std::vector< std::vector< int > > getPairs(
            const std::vector< std::vector< int > >& a
        ,   const std::vector< std::vector< int > >& b
        ,   int target
    )
    {
        std::vector< std::vector< int > > result;
        int maxSum = std::numeric_limits< int >::min();

        for( int i = 0; i < a.size(); ++i ) {
            for( int j = 0; j < b.size(); ++j ) {
                const int currSum = a[ i ][ 1 ] + b[ j ][ 1 ];
                if( currSum <= target && currSum >= maxSum ) {
                    if( currSum > maxSum ) {
                        maxSum = currSum;
                        result.clear();
                    }

                    result.push_back( { a[ i ][ 0 ], b[ j ][ 0 ] } );
                }
            }
        }

        return result;
    }
}; // class PriveAirRoute

int main() {
    PriveAirRoute solution;

    // Example 1
    vector<vector<int>> a = {{1, 2}, {2, 4}, {3, 6}};
    vector<vector<int>> b = {{1, 2}};
    vector<vector<int>> expectedResult = {{2, 1}};
    assert(solution.getPairs(a, b, 7) == expectedResult);

    // Example 2
    a = {{1, 3}, {2, 5}, {3, 7}, {4, 10}};
    b = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    expectedResult = {{2, 4}, {3, 2}};
    assert(solution.getPairs(a, b, 10) == expectedResult);

    // Example 3
    a = {{1, 8}, {2, 7}, {3, 14}};
    b = {{1, 5}, {2, 10}, {3, 14}};
    expectedResult = {{3, 1}};
    assert(solution.getPairs(a, b, 20) == expectedResult);

    // Example 4
    a = {{1, 8}, {2, 15}, {3, 9}};
    b = {{1, 8}, {2, 11}, {3, 12}};
    expectedResult = {{1, 3}, {3, 2}};
    assert(solution.getPairs(a, b, 20) == expectedResult);

    return 0;
}
} // namespace

namespace {
/*
https://leetcode.com/discuss/interview-question/373202/Amazon-or-OA-2019-or-Optimal-Utilization/459822

Solution requires mutable input

N - size of a
M - size of b

Time O(N*M) - worst case, O(N+M) - best case, when result is empty
Space O(1) if ignoring output result
*/
class PriveAirRoute {
public:
    std::vector< std::vector< int > > getPairs(
            std::vector< std::vector< int > >& a
        ,   std::vector< std::vector< int > >& b
        ,   int target
    )
    {
        auto comparator = []( const auto& lhs, const auto& rhs ) {
            return lhs[ 1 ] < rhs[ 1 ];
        };
        std::sort( begin( a ), end( a ), comparator );
        std::sort( begin( b ), end( b ), comparator );

        std::vector< std::vector< int > > result;
        
        int maxSum = std::numeric_limits< int >::min();

        int i = 0;
        int j = b.size() - 1;

        while( i < a.size() && j >= 0 ) {
            const int sum = a[ i ][ 1 ] + b[ j ][ 1 ];

            if( sum > target ) { // skip value of b
                --j;
            }
            else {
                if( sum >= maxSum ) {
                    if( sum > maxSum ) { // // we have found a better solution, clear previous one
                        maxSum = sum;
                        result.clear();
                    }

                    result.push_back( { a[ i ][ 0 ], b[ j ][ 0 ] } );

                    // index j only moves when sum > target. if sum == current_max and b[j] == b[j-1]
                    // without the following 4 lines we would be incrementing i, losing C-1 solutions
                    // where C is the number of consecutive repeated values equal to b[j].
                    int prev = j - 1;
                    while( prev >= 0 && b[ prev ][ 1 ] == b[ j ][ 1 ] ) {
                        result.push_back( { a[ i ][ 0 ], b[ prev ][ 0 ] } );
                        --prev;
                    }
                }

                ++i;
            }
        }

        return result;
    }
}; // class PriveAirRoute

int main() {
    PriveAirRoute solution;

    // Example 1
    vector<vector<int>> a = {{1, 2}, {2, 4}, {3, 6}};
    vector<vector<int>> b = {{1, 2}};
    vector<vector<int>> expectedResult = {{2, 1}};
    assert(solution.getPairs(a, b, 7) == expectedResult);

    // Example 2
    a = {{1, 3}, {2, 5}, {3, 7}, {4, 10}};
    b = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    expectedResult = {{2, 4}, {3, 2}};
    assert(solution.getPairs(a, b, 10) == expectedResult);

    // Example 3
    a = {{1, 8}, {2, 7}, {3, 14}};
    b = {{1, 5}, {2, 10}, {3, 14}};
    expectedResult = {{3, 1}};
    assert(solution.getPairs(a, b, 20) == expectedResult);

    // Example 4
    a = {{1, 8}, {2, 15}, {3, 9}};
    b = {{1, 8}, {2, 11}, {3, 12}};
    expectedResult = {{1, 3}, {3, 2}};
    assert(solution.getPairs(a, b, 20) == expectedResult);

    return 0;
}
} // namespace