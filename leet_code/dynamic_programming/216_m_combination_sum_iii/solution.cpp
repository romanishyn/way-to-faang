/*
https://leetcode.com/problems/combination-sum-iii/
*/

#include <vector>

using std::vector;

namespace {
/*
C(n,r) = n!/((n-r)!*r!)
n - number of objects
r - how many objects taken at a time


*/
class Solution {
    using Path = std::vector< int >;
    using Result = std::vector< Path >;

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        Result result;
        Path path;
        fillCombinationSum3( result, path, k, n, 1 );
        return result;
    }

private:
    void fillCombinationSum3( Result& result, Path& path, int k/*size of path*/, int remainingPathSum, int startNum ) {
        if( path.size() == k ) {
            if( remainingPathSum == 0 )
                result.push_back( path );

            return;
        }

        for( int i = startNum; i <= 9 && i <= remainingPathSum; ++i ) {
            path.push_back( i );
            fillCombinationSum3( result, path, k, remainingPathSum - i, i + 1 );
            path.pop_back();
        }
    }
};
} // namespace

namespace {
class Solution {
    using Path = std::vector< int >;
    using Result = std::vector< Path >;

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        Result result;
        Path path;
        fillCombinationSum3( result, path, k, n, 9 );
        return result;
    }

private:
    void fillCombinationSum3( Result& result, Path& path, int k, int remainingSum, int startNum ) {
        if( path.size() == k ) {
            if( remainingSum == 0 )
                result.push_back( path );
            
            return;
        }

        for( int i = startNum; i >= 1; --i ) {
            if( i > remainingSum )
                continue;

            path.push_back( i );
            fillCombinationSum3( result, path, k, remainingSum - i, i - 1 );
            path.pop_back();
        }
    }
};
} // namespace