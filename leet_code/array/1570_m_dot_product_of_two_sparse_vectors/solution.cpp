/*
https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
Base on hash map

N - size of this.idxToValue
M - size of vec.idxToValue

dotProduct:
Time O(min(N,M))
Space O(1)
*/
class SparseVector {
    std::unordered_map< int, int > idxToValue;

public:

    SparseVector(vector<int> &nums) {
        for( int i = 0; i < nums.size(); ++i )
            if( nums[ i ] != 0 )
                idxToValue[ i ] = nums[ i ];
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if( idxToValue.size() > vec.idxToValue.size() )
            return vec.doProduct( *this );

        int ans = 0;
        for( auto [idx, value] : idxToValue ) {
            if( auto it = vec.idxToValue.find( idx ); it != vec.idxToValue.end() ) {
                ans += value * it->second;
            }
        }

        return ans;
    }
};
} // namespace

namespace {
/*
Base on two pointers

N - size of this.idxToValue
M - size of vec.idxToValue

dotProduct:
Time O(min(N,M))
Space O(1)
*/
class SparseVector {
    std::vector< std::pair< int, int > > idxToValue;

public:

    SparseVector(vector<int> &nums) {
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] != 0 )
                idxToValue.emplace_back( i, nums[ i ] );
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        int i = 0;
        int j = 0;
        while( i < idxToValue.size() && j < vec.idxToValue.size() ) {
            if( idxToValue[ i ].first < vec.idxToValue[ j ].first ) {
                ++i;
            }
            else if( idxToValue[ i ].first > vec.idxToValue[ j ].first ) {
                ++j;
            }
            else {
                product += idxToValue[ i ].second * vec.idxToValue[ j ].second;
                ++i;
                ++j;
            }
        }

        return product;
    }
};
} // namespace
