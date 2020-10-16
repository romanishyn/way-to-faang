/*
https://leetcode.com/problems/trapping-rain-water/
*/

namespace {
/*
LC: TLE
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        int left = 0;
        int right = height.size() - 1;
        for( int currHeight = 0; left < right; ++currHeight ) {
            while( left < right && currHeight >= height[ left ] )
                ++left;
            while( left < right && currHeight >= height[ right ] )
                --right;

            for( int i = left; i < right; ++i ) {
                if( height[ i ] <= currHeight )
                    ++count;
            }
        }

        return count;
    }
};
} // namespace

namespace {
/*
For each position find max[0,i] and [i,size-1],
find maximum borders on the left and on the right sides, and minus height of arr[ i ]
allows us compute how many water is in current position

N - size of height

Time O(N^2)
Space O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int countWater = 0;
        
        const int size = height.size();
        for( int i = 0; i < size; ++i ) {
            int maxLeft = 0;
            for( int j = 0; j <= i; ++j )
               maxLeft = std::max( maxLeft, height[ j ] );

           int maxRight = 0;
           for( int j = i; j < size; ++j )
               maxRight = std::max( maxRight, height[ j ] );

           countWater += std::min( maxLeft, maxRight ) - height[ i ];
        }

        return countWater;
    }
};
} // namespace

namespace {
/*
The same idea as above, but we can precompute and cache maximum values from left to right and vice versa.

N - size of height

Time O(N)
Space O(N)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if( height.empty() )
            return 0;

        const int size = height.size();

        std::vector< int > leftMaxValues( size );
        leftMaxValues[ 0 ] = height[ 0 ];
        for( int i = 1; i < size; ++i )
            leftMaxValues[ i ] = std::max( leftMaxValues[ i - 1 ], height[ i ] );

        std::vector< int > rightMaxValues( size );
        rightMaxValues[ size - 1 ] = height[ size - 1 ];
        for( int i = size - 2; i >= 0; --i )
            rightMaxValues[ i ] = std::max( rightMaxValues[ i + 1 ], height[ i ] );

        int countWater = 0;
        for( int i = 0; i < size; ++i )
            countWater += std::min( leftMaxValues[ i ], rightMaxValues[ i ] ) - height[ i ];

        return countWater;
    }
};
} // namespace

namespace {
/*
Find first global max border.
Then go from left to right [0, maxBorderIdx), calculate currMaxBorder, and if arr[ i ] < currMaxBorder  add difference to the result.
The same for right to left (maxBorderIdx,size-1]

N - size of heigth

Time O(N)
Space O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        auto [maxBorder, maxBorderIdx] = findFirstMaxBorder( height );

        int countWater = 0;
        int currMaxLeft = -1;
        for( int i = 0; i < maxBorderIdx; ++i ) {
            if( height[ i ] >= currMaxLeft ) {
                currMaxLeft = height[ i ];
            }
            else {
                countWater += currMaxLeft - height[ i ];
            }
        }

        int currMaxRight = -1;
        for( int i = height.size() - 1; i > maxBorderIdx; --i ) {
            if( height[ i ] >= currMaxRight ) {
                currMaxRight = height[ i ];
            }
            else {
                countWater += currMaxRight - height[ i ];
            }
        }

        return countWater;
    }

    std::pair< int, int > findFirstMaxBorder( const vector<int>& height) {
        int maxBorder = -1;
        int maxBorderIdx = -1;
        
        for( int i = 0 ; i < height.size(); ++i ) {
            if( height[ i ] > maxBorder ) {
                maxBorder = height[ i ];
                maxBorderIdx = i;
            }
        }
        
        return { maxBorder, maxBorderIdx };
    }
};
} // namespace

namespace {
/*
Two pointers

N - size of height

Time O(N)
Space O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxLeftHeight = -1;
        int maxRightHeight = -1;

        int totalWater = 0;

        while( left < right ) {
            if( height[ left ] < height[ right ] ) {
                if( height[ left ] >= maxLeftHeight )
                    maxLeftHeight = height[ left ];
                else
                    totalWater += maxLeftHeight - height[ left ];

                ++left;
            }
            else {
                if( height[ right ] >= maxRightHeight )
                    maxRightHeight = height[ right ];
                else
                    totalWater = maxRightHeight - height[ right ];

                --right;
            }
        }

        return totalWater;
    }
};
} // namespace
