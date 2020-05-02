/*
https://leetcode.com/problems/course-schedule/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <stack>

using std::vector;

class Solution {
public:
    using Graph = vector< vector< int > >;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph( numCourses );
        for( const auto& item: prerequisites ) {
            graph[ item[ 0 ] ].push_back( item[ 1 ] );
        }

        vector< bool > stack( numCourses );
        vector< bool > visited( numCourses );

        for( int i = 0; i < numCourses; ++i ) {
            if( !visited[ i ] && isCyclic( graph, stack, visited, i ) )
                return false;
        }

        return true;
    }

    bool isCyclic( const Graph& graph, vector< bool >& stack, vector< bool >& visited, int v ) {
        stack[ v ] = true;

        for( int adj : graph[ v ] ) {
            if( visited[ adj ] )
                continue;

            if( stack[ adj ] )
                return true;

            if( isCyclic( graph, stack, visited, adj ) )
                return true;
        }

        visited[ v ] = true;
        stack[ v ] = false;

        return false;
    }
};

//class Solution {
//public:
//    using Graph = vector< vector< int > >;
//
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        Graph graph( numCourses );
//        for( const auto& item: prerequisites ) {
//            graph[ item[ 0 ] ].push_back( item[ 1 ] );
//        }
//
//        vector< int > visited( numCourses, 0 );
//
//        for( int i = 0; i < numCourses; ++i ) {
//            if( ( visited[ i ] == 0 ) && isCyclic( graph, visited, i ) )
//                return false;
//        }
//
//        return true;
//    }
//
// 0 - white
// 1 - gray
// 2 - black
//    bool isCyclic( const Graph& graph, vector< int >& visited, int v ) {
//        visited[ v ] = 1;
//
//        for( int adj : graph[ v ] ) {
//            if( visited[ adj ] == 2 )
//                continue;
//
//            if( visited[ adj ] == 1 )
//                return true;
//
//            if( isCyclic( graph, visited, adj ) )
//                return true;
//        }
//
//        visited[ v ] = 2;
//
//        return false;
//    }
//};
