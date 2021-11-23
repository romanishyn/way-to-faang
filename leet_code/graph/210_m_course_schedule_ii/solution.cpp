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

namespace {
/*
N - numCourses
M - prerequisites.size

Time O(N+M)
Space O(N+M)
*/
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		std::vector< int > inDegree(numCourses);
		std::unordered_map< int, std::vector< int > > graph;

		for (const auto& pair : prerequisites) {
			++inDegree[pair[0]];
			graph[pair[1]].push_back(pair[0]);
		}

		std::queue< int > zeroNodes;
		for (int i = 0; i < inDegree.size(); ++i) {
			if (inDegree[i] == 0)
				zeroNodes.push(i);
		}

		std::vector< int > result;
		while (!zeroNodes.empty()) {
			int node = zeroNodes.front();
			zeroNodes.pop();

			result.push_back(node);

			for (int adj : graph[node]) {
				if (--inDegree[adj] == 0)
					zeroNodes.push(adj);
			}
		}

		return result.size() == numCourses ? result : std::vector< int >{};
	}
};
} // namespace