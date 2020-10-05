/*
https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
*/

namespace {
/*
N - number of rows
M - number of cols

Time O(NlogM)
Space O(1)
*/

  // This is the BinaryMatrix's API interface.
  // You should not implement it, or speculate about its implementation
  class BinaryMatrix {
    public:
      int get(int row, int col);
      vector<int> dimensions();
  };
 

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int rows = binaryMatrix.dimensions()[ 0 ];
        const int cols = binaryMatrix.dimensions()[ 1 ];

        int ans = cols;
        for( int i = 0; i < rows; ++i ) {
            int left = 0;
            int right = ans - 1;
            while( left <= right ) {
                int mid = left + ( right - left ) / 2;
                if( binaryMatrix.get( i, mid ) == 1 ) {
                    ans = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }

        return ans == cols ? -1 : ans;
    }
};
} // namespace

namespace {
/*
N - number of rows
M - number of cols

Time O(N + M)
Space O(1)
*/

  // This is the BinaryMatrix's API interface.
  // You should not implement it, or speculate about its implementation
  class BinaryMatrix {
    public:
      int get(int row, int col);
      vector<int> dimensions();
  };
 
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int rows = binaryMatrix.dimensions()[ 0 ];
        const int cols = binaryMatrix.dimensions()[ 1 ];
        
        int col = cols;
        for( int i = 0; i < rows; ++i ) {
            while( col > 0 && binaryMatrix.get( i, col - 1 ) == 1 )
                --col;
        }

        return col == cols ? -1 : col;
    }
};
} // namespace

namespace {
/*
N - number of rows
M - number of cols

Time O(N + M)
Space O(1)
*/

  // This is the BinaryMatrix's API interface.
  // You should not implement it, or speculate about its implementation
  class BinaryMatrix {
    public:
      int get(int row, int col);
      vector<int> dimensions();
  };

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int rows = binaryMatrix.dimensions()[ 0 ];
        const int cols = binaryMatrix.dimensions()[ 1 ];

        int col = cols;
        int row = 0;
        while( row < rows && col > 0 ) {
            if( binaryMatrix.get( row, col - 1 ) == 1 )
                --col;
            else
                ++row;
        }

        return col == cols ? -1 : col;
    }
};
} // namespace