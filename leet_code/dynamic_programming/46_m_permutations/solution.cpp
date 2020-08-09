/*
 * https://leetcode.com/problems/permutations/
 * */

#include <queue>
#include <vector>

using std::vector;

/*
                                x
                    x           x             x
                  x   x       x   x         x   x
                  x   x       x   x         x   x        
*/

namespace V1 {
/*
 * used[ i ] is true, if nums[ i ] is used
 *
 * N - size of nums
 *
 * Space O(N*N!)
 * */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path( nums.size() );
        vector<bool> used( nums.size() );
        fillPermutation( nums, result, path, used, 0 );
        return result;
    }

private:
    void fillPermutation( const vector<int>& nums,
                          vector< vector< int > >& result,
                          vector< int >& path,
                          vector< bool >& used,
                          int pathIdx ) {
        if( pathIdx == path.size() ) {
            result.push_back( path );
            return;
        }

        for( int i = 0; i < nums.size(); ++i ) {
            if( used[ i ] )
                continue;

            used[ i ] = true;
            path[ pathIdx ] = nums[ i ];
            fillPermutation( nums, result, path, used, pathIdx + 1 );
            used[ i ] = false;
        }
    }
};
} // namespace V1

namespace V2 {
/*
 * used[ i ] is true, is path[ i ] is used
 *
 * N - size of nums
 *
 * Space O(N*N!)
 * */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path( nums.size() );
        vector<bool> used( nums.size() );
        fillPermutation( nums, result, path, used, 0 );
        return result;
    }

private:
    void fillPermutation( const vector<int>& nums,
                          vector< vector< int > >& result,
                          vector< int >& path,
                          vector< bool >& used,
                          int numIdx ) {
        if( numIdx == nums.size() ) {
            result.push_back( path );
            return;
        }

        for( int i = 0; i < path.size(); ++i ) {
            if( used[ i ] )
                continue;

            used[ i ] = true;
            path[ i ] = nums[ numIdx ];
            fillPermutation( nums, result, path, used, numIdx + 1 );
            used[ i ] = false;
        }
    }
};
} // namespace V2

namespace V3 {
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        std::queue< std::vector< int > > permutations;
        permutations.push( {} );

        for( int num : nums ) {
            const int levelSize = permutations.size();

            for( int i = 0; i < levelSize; ++i ) {
                auto oldPermute = permutations.front();
                permutations.pop();

                for( int pos = 0; pos <= oldPermute.size(); ++pos ) {
                    auto newPermute = oldPermute;
                    newPermute.insert( newPermute.begin() + pos, num );

                    if( newPermute.size() == nums.size() ) {
                        result.push_back( std::move( newPermute ) );
                    }
                    else {
                        permutations.push( newPermute );
                    }
                }
            }
        }

        return result;
    }
};
} // namespace V3

