/*
https://leetcode.com/problems/course-schedule-ii/
*/

namespace {
/*
Using BFS topological sort

V - number of courses
E - number of prerequisites

Time O(V+E)
Space O(V+E)
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int > > graph( numCourses );
        vector< int > inDegree( numCourses );
        
        for( const auto& entry: prerequisites ) {
            graph[ entry[ 1 ] ].push_back( entry[ 0 ] );
            ++inDegree[ entry[ 0 ] ];
        }

        std::queue< int > sources;
        for( int i = 0; i < inDegree.size(); ++i ) {
            if( inDegree[ i ] == 0 ) {
                sources.push( i );
            }
        }

        std::vector< int > sortedCourses;
        while( ! sources.empty() ) {
            int cource = sources.front();
            sources.pop();
            sortedCourses.push_back( cource );
            
            for( int adj : graph[ cource ] ) {
                if( --inDegree[ adj ] == 0 )
                    sources.push( adj );
            }
        }

        return sortedCourses.size() == numCourses ? sortedCourses : vector< int >{} ;
    }
};
} // namespace