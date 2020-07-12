/*
 * https://leetcode.com/problems/subsets/
 * */

#include <vector>

using std::vector;

namespace V1 {
/*
 * It solution is similar to Knapsack problem (choose or not choose)
 *
 * N - number of elements in nums
 * Time (N*2^(N+1), 2^(N+1) is how many operation, one operation costs N, since we need copy of set
 * Space(N*2^N), 2^N total number of sets, N is length of one set
 * */
class Solution {
public:
    using Subsets = vector<vector<int>>;

    vector<vector<int>> subsets(vector<int>& nums) {
        Subsets subsets;
        fillSublets( nums, subsets, 0, {} );
        return subsets;
    }

private:
    void fillSublets( const vector<int>& nums, Subsets& subsets, int idx, vector< int > set ) {
        if( idx == nums.size() ) {
            subsets.push_back( std::move( set ) );
            return;
        }

        auto withCurrentValue{ set }; ;

        withCurrentValue.push_back( nums[ idx ] );

        fillSublets( nums, subsets, idx + 1, std::move( set ) );
        fillSublets( nums, subsets, idx + 1, std::move( withCurrentValue ) );
    }
};
} // namespace V1

namespace V2 {
/*
 * Cascading approach
 *
 * Example:
 * nums = {1,2,3}
 * {}
 * {1}
 * {2} {1,2}
 * {3} {1,3} {2,3} {1,2,3}
 *
 * N = number of elements in nums
 * Time (N*2^N)
 * Space (N*2^N)
 * */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        subsets.push_back( {} );

        for( int i = 0; i < nums.size(); ++i ) {
            const int size = subsets.size();
            for( int j = 0; j < size; ++j ) {
                auto newSet = subsets[ j ];
                newSet.push_back( nums[ i ] );
                subsets.push_back( std::move( newSet ) );
            }
        }

        return subsets;
    }
};
} // namespace V2

namespace V3 {
/*
 * Backtracking approach
 *
 * Example:
 * nums: [1,2,3]
 *
 *                               []
 *           [1]                 [2]            [3]
 *      [1,2]     [1,3]         [2,3]
 * [1,2,3]
 *
 *
 * N - number of elements in nums
 *
 * Time (N*2^N), N - need make copy on each iteration, 2^N number of operations (calls of subsets())
 * Space (N*2^N)
 * */
class Solution {
public:
    using Set = std::vector< int >;
    using Subsets = std::vector< Set >;

    vector<vector<int>> subsets(vector<int>& nums) {
        Subsets paths;
        Set path;
        subsets( nums, paths, 0, path );
        return paths;
    }

    void subsets( const vector<int>& nums, Subsets& paths, int idx, Set& path ) {
        paths.push_back( path );

        for( int i = idx; i < nums.size(); ++i ) {
            path.push_back( nums[ i ] );
            subsets( nums, paths, i + 1, path );
            path.pop_back();
        }
    }
};
} // namespace V3

namespace V4 {
class Solution {
public:
    using Set = std::vector< int >;
    using Subsets = std::vector< Set >;

    vector<vector<int>> subsets(vector<int>& nums) {
        Subsets subsets;
        const int subsetCount = ( 1 << nums.size() );

        for( int i = 0; i < subsetCount; ++i ) {
            Set set;
            for( int j = 0; j < nums.size(); ++j ) {
                if( ( i >> j ) & 1 )
                    set.push_back( nums[ j ] );
            }

            subsets.push_back( std::move( set ) );
        }

        return subsets;
    }
};
} // namespace V4
