/*
https://leetcode.com/discuss/interview-question/865660/
*/

#include <vector>

namespace {
/*
1234567
|**|*|*

1-4: 2
4-6: 1

1:0
4:2
6:3

Create runningSumVector
for each start+end find boundary, then calculate the number of asterisks between them

N - size of str
M - number of coordinate pairs

Time O(NlogM)
Space O(N) - O(N) in case when str contains only pipes
*/

class ItemsInContainers {
public:
    std::vector< int > getItems(
        const std::string& str,
        const std::vector< int >& startIndices,
        const std::vector< int >& endIndeces
    )
    {
        int runningSum = 0;
        std::vector< std::pair< int, int > > idxToItems;

        for( int i = 0; i < str.size(); ++i ) {
            if( str[ i ] == '*' )
                ++runningSum;
            else
                idxToItems.emplace_back( i + 1, runningSum );
        }

        std::vector< int > result;

        for( int i = 0; i < startIndices.size(); ++i ) {
            int start = findStart( startIndices[ i ], idxToItems );
            int end = findEnd( endIndeces[ i ], idxToItems );
            if( start != -1 && end != -1 ) {
                result.push_back( idxToItems[ end ].second - idxToItems[ start ].second );
            }
            else {
                result.push_back( 0 );
            }
        }

        return result;
    }

private:
    int findStart( int currIdx, const std::vector< std::pair< int, int > >& idxToItems ) {
        int left = 0;
        int right = idxToItems.size() - 1;

        int ans = -1;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;
            if( idxToItems[ mid ].first >= currIdx ) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    int findEnd( int currIdx, const std::vector< std::pair< int, int > >& idxToItems ) {
        int left = 0;
        int right = idxToItems.size() - 1;

        int ans = -1;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;
            if( idxToItems[ mid ].first <= currIdx ) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    ItemsInContainers solution;

    std::string str = "|**|*|*";
    std::vector< int > startIndices = { 1, 1 };
    std::vector< int > endIndeces = { 5, 6 };
    std::vector< int > expectedResult = { 2, 3 };
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    str = "*|*|";
    startIndices = {1};
    endIndeces = {3};
    expectedResult = {0};
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    str = "|**|*|";
    startIndices = {1};
    endIndeces = {5};
    expectedResult = {2};
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    str = "****|*|";
    startIndices = {1, 5, 3};
    endIndeces = {3, 7, 7};
    expectedResult = {0, 1, 1};
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    str = "**|*|*||*||***|*|";
    startIndices =  {1, 5, 3};
    endIndeces = {3, 7, 9};
    expectedResult = {0, 1, 2};
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    str = "*****************";
    startIndices =  {1, 6, 3};
    endIndeces = {3, 7, 9};
    expectedResult = {0, 0, 0};
    assert( solution.getItems( str, startIndices, endIndeces ) == expectedResult );

    return 0;
}
} // namespace
