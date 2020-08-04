/*
 * https://leetcode.com/problems/subsets-ii/
 * */

#include <vector>
#include <algorithm>

using std::vector;

namespace V1 {
/*
 * Backtracking approach
 *
 * Need sort numbers to handle duplicates
 * At each recursion call add current path to the result
 * TODO: describe
 *
 * N - #nums
 *
 * Time (N*2^N)
 * Space (N*2^N)
 * */
class Solution {
    using Set = vector<int>;
    using Subsets = vector<Set>;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        Subsets result;
        Set path;
        fillSubsets( nums, result, path, 0 );
        return result;
    }
private:
    void fillSubsets( const vector<int>& nums, Subsets& result, Set& path, int idx ) {
        result.push_back( path );

        for( int i = idx; i < nums.size(); ++i ) {
            if( i > idx && nums[ i ] == nums[ i - 1 ] )
                continue;

            path.push_back( nums[ i ] );
            fillSubsets( nums, result, path, i + 1 );
            path.pop_back();
        }
    }
};
} // namespace V1


namespace V2 {
/*
 * Knapsack problem approach
 *
 * To avoid duplication on step "not choose" we check if current path is not empty and current element different from last element in path.
 * It guarantees that we do not choose a path which has already considered
 *
 * Time (N*2^(N+1)
 * Space (N*2^N)
 * */
class Solution {
    using Set = vector<int>;
    using Subsets = vector<Set>;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std:sort( nums.begin(), nums.end() );
        Subsets result;
        Set path;
        fillSubsets( nums, result, path, 0 );
        return result;
    }
private:
    void fillSubsets(vector<int>& nums, Subsets& result, Set& path, int idx ) {
        if( idx == nums.size() ) {
            result.push_back( path );
            return;
        }

        if( path.empty() || nums[ idx ] != path.back() ) {
            fillSubsets( nums, result, path, idx + 1 );
        }

        path.push_back( nums[ idx ] );
        fillSubsets( nums, result, path, idx + 1 );
        path.pop_back();
    }
};
} // namespace V2

namespace V3 {
/*
 * Breadth First Search
 *
 * Time (N*2^N)
 * Space (N*2^N)
 * */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std:sort( nums.begin(), nums.end() );

        vector<vector<int>> result{ {}  };
        int end = 0;
        for( int i = 0; i < nums.size(); ++i ) {
            int start = 0;
            if( i != 0 && nums[ i ] == nums[ i - 1 ] )
                start = end;

            end = result.size();

            for( int j = start; j < end; ++j ) {
                auto set = result[ j ];
                set.push_back( nums[ i ] );
                result.push_back( std::move( set ) );
            }
        }

        return result;
    }
};
} // namespace V3
