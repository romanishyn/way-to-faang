/*
https://leetcode.com/discuss/interview-question/933383/
*/

#include <vector>
#include <queue>

namespace {
/*

*/
class Solution {
public:
    int minChange( std::vector< std::vector< int > > &productRatings, int ratingsThreshold ) {
        const int n = productRatings.size();

        const double threshold = ratingsThreshold * n / 100.0;

        int changes = 0;
        double currPercent = 0;

        // operator <, top value is max value
        auto comparator = []( const auto& lhs, const auto& rhs ) {
            if( lhs[ 0 ] == lhs[ 1 ] )
                return true;
            if( rhs[ 0 ] == rhs[ 1 ] )
                return false;

            return  static_cast< double >( lhs[ 0 ] + 1 ) / ( lhs[ 1 ] + 1 ) - static_cast< double >( lhs[ 0 ] ) / ( lhs[ 1 ] )
                <   static_cast< double >( rhs[ 0 ] + 1 ) / ( rhs[ 1 ] + 1 ) - static_cast< double >( rhs[ 0 ] ) / ( rhs[ 1 ] );
        };
        std::priority_queue< std::vector< int >, std::vector< std::vector< int > >, decltype( comparator ) > maxHeap( comparator );

        for( const auto& prod : productRatings ) {
            currPercent += static_cast< double >( prod[ 0 ] ) / prod[ 1 ];
            maxHeap.push( prod );
        }

        while( currPercent < threshold ) {
            ++changes;

            auto maxRating = maxHeap.top();
            maxHeap.pop();

            currPercent -= static_cast< double >( maxRating [ 0 ] ) / maxRating[ 1 ];

            ++maxRating[ 0 ];
            ++maxRating[ 1 ];

            currPercent += static_cast< double >( maxRating [ 0 ] ) / maxRating[ 1 ];
            maxHeap.push( maxRating );
        }

        return changes;
    }
}; // class Solution

int main() {
  // tests copied from https://leetcode.com/discuss/interview-question/933383/Amazon-or-OA-2020-or-Five-Star-Sellers/762280
    auto test = [ i = 1 ](Solution &sol, vector<vector<int>> &productRatings,
            int &ratingsThreshold, int &expected) mutable {
    cout << "Run test case " << i++ << endl;
    auto res = sol.minChange(productRatings, ratingsThreshold);
    cout << res << endl;
    cout << expected << endl;

    assert(res == expected);
    cout << "Success!" << endl;
    };

    Solution sol;
    vector<vector<int>> productRatings1 = {{4, 4}, {1, 2}, {3, 6}};
    int ratingsThreshold1 = 77;
    int expected1 = 3;
    test(sol, productRatings1, ratingsThreshold1, expected1);

    vector<vector<int>> productRatings2 = {{9, 10}};
    int ratingsThreshold2 = 91;
    int expected2 = 2;
    test(sol, productRatings2, ratingsThreshold2, expected2);

    vector<vector<int>> productRatings3 = {{1, 3}, {1, 4}};
    int ratingsThreshold3 = 60;
    int expected3 = 6;
    test(sol, productRatings3, ratingsThreshold3, expected3);

    return 0;
}
} // namespace
