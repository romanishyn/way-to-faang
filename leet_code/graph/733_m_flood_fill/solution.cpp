/*
https://leetcode.com/problems/flood-fill/
*/

#include <vector>

using std::vector;

namespace {
/*
DFS

N - rows
M - cols

Time O(N*M)
Space O(N*M)
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if( newColor == image[ sr ][ sc ] )
            return image;

        auto newImage = image;
        int currColor = image[ sr ][ sc ];

        std::stack< std::pair< int, int > > todo;
        todo.emplace( sr, sc );
        newImage[ sr ][ sc ] = newColor;

        std::vector< std::pair< int, int > > coordinates{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        while( ! todo.empty() ) {
            auto [ row, col ] = todo.top();
            todo.pop();

            for( const auto [ x, y ] : coordinates ) {
                int nRow = row + x;
                int nCol = col + y;

                if( nRow < 0 || nRow >= image.size() || nCol < 0 || nCol >= image[ 0 ].size() )
                    continue;
                if( newImage[ nRow ][ nCol ] != currColor )
                    continue;

                newImage[ nRow ][ nCol ] = newColor;
                todo.emplace( nRow, nCol );
            }
        }

        return newImage;
    }
};
} // namespace
