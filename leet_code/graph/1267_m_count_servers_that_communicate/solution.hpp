/*
https://leetcode.com/problems/count-servers-that-communicate/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <stack>
#include <functional>

using std::vector;

namespace V1 {
/*
 * Explore all grid and store number of servers in each row and column,
 * for this we can use two collection, vectors of integers.
 * Index in a vector is the index of column or row respectively.
 * Also store all position of servers in separate collection,
 * it helps us to iterate over this position again, because I am gonna
 * assign -1 each new visited cell to prevent repetition of visiting the same cell during dfs.
 * And finally if count all not isolated servers.
 * Time: O(n2)
 * Space: O(n2)
 * */
class Solution {
public:
    using Grid = vector< vector< int > >;
    using Servers = vector< std::pair< int, int > > ;
    using Counter = vector< int >;

    int countServers( vector< vector< int>> & grid ) {
        if( grid.empty() )
            return 0;

        Servers servers;
        Counter rowCounter( grid.size() );
        Counter columnCounter( grid[ 0 ].size() );

        dfs( grid, 0, 0, rowCounter, columnCounter, servers );

        int result = 0;

        for( auto [ row, col ] : servers ) {
            if( rowCounter[ row ] > 1 || columnCounter[ col ] > 1 )
                ++result;
        }

        return result;
    }

    void dfs( Grid& grid, int row, int col, Counter& rowCounter, Counter& colCounter, Servers& servers ) {
        if( row < 0 || row > grid.size() - 1 || col < 0 || col > grid[ 0 ].size() - 1 )
            return;
        if( grid[ row ][ col ] == -1 )
            return;

        if( grid[ row ][ col ] == 1 ) {
            ++rowCounter[ row ];
            ++colCounter[ col ];
            servers.emplace_back( row, col );
        }

        grid[ row ][ col ] = -1;

        dfs( grid, row - 1, col, rowCounter, colCounter, servers );
        dfs( grid, row + 1, col, rowCounter, colCounter, servers );
        dfs( grid, row, col - 1, rowCounter, colCounter, servers );
        dfs( grid, row, col + 1, rowCounter, colCounter, servers );
    }
};
} // namespace V1

namespace V2 {
/*
 * Need to store number of servers in each row and column.
 * Then iterate over grid again, and count all not isolated servers.
 * Store of number of servers it's like cache. It helps us to count result,
 * when we will iterate again and encounter server we can understand it's isolated or not.
 * Time: O(n2)
 * Space: O(n)
 * */
class Solution {
public:
    int countServers( vector< vector< int>> & grid ) {
        if( grid.empty() )
            return 0;

        vector< int > rowCounter( grid.size() );
        vector< int > colCounter( grid[ 0 ].size() );

        forEach(
            grid, [ & ]( int row, int col, int val ) {
                if( val == 1 ) {
                    ++rowCounter[ row ];
                    ++colCounter[ col ];
                }
            }
        );

        int result = 0;
        forEach(
            grid,
            [ & ]( int row, int col, int val ) {
                if( val == 1 && ( rowCounter[ row ] > 1 || colCounter[ col ] > 1 ) )
                    ++result;
            }
        );

        return result;
    }

    void forEach( const vector< vector< int>> & grid, std::function< void( int, int, int ) > callback ) {
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                callback( i, j, grid[ i ][ j ] );
            }
        }
    }
};
} // namespace V2
