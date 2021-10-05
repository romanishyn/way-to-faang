/*
https://leetcode.com/problems/task-scheduler/
*/

#include <vector>
#include <queue>
#include <unordered_map>

using std::vector;

namespace {
/*
N - number of tasks
Nt - total number of CPU operations - answer of problem

Time O(max(NlogN, Nt))
Space O(N)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map< char, int > taskCount;
        for( char task : tasks )
            ++taskCount[ task ];

        std::priority_queue< int > maxHeap;
        for( auto [_, count] : taskCount )
            maxHeap.push( count );

        std::queue< std::pair< int, int > > waitingTasks;

        constexpr int idle = 0;

        int units = 0;
        while( ! maxHeap.empty() || ! waitingTasks.empty() ) {
            ++units;

            if( ! maxHeap.empty() ) {
                int task = maxHeap.top();
                maxHeap.pop();

                --task;
                if( task > 0 )
                    waitingTasks.emplace( task, units );
            }

            if( ! waitingTasks.empty() ) {
                auto [task, ts] = waitingTasks.front();
                if( units - ts >= n ) {
                    waitingTasks.pop();
                    maxHeap.push( task );
                }
            }
        }

        return units;
    }
};
} // namespace

namespace {
/*
N - number of tasks

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map< char, int > taskToFrequency;
        for( char task : tasks )
            ++taskToFrequency[ task ];

        std::priority_queue< int > maxHeap;
        for( auto [_, taskCount] : taskToFrequency )
            maxHeap.push( taskCount );

        int result = 0;
        while( ! maxHeap.empty() ) {
            std::vector< int > doneTasks;
            int ticks = n + 1;
            while( ticks && ! maxHeap.empty() ) {
                --ticks;
                auto task = maxHeap.top();
                maxHeap.pop();
                --task;
                if( task > 0 )
                    doneTasks.push_back( task );
            }

            result += n + 1 - ticks;
            if( ! doneTasks.empty() ) {
                result += ticks;
                for( int task : doneTasks )
                    maxHeap.push( task );
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
N = tasts.size

Time O(N)
Space O(1)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map< char, int > jobToCount;
        for( char job : tasks )
            ++jobToCount[ job ];
        
        using Task = std::pair< char, int >;
        auto comparator = []( const Task& lhs, const Task& rhs ) {
            return lhs.second < rhs.second;
        };
               
        std::priority_queue< Task, std::vector< Task >, decltype( comparator ) > maxHeap( comparator );
        
        for( const Task& task : jobToCount )
            maxHeap.push( task );
        
        int units = 0;
        
        std::queue< std::pair< Task, int > > waiting;
        
        while( ! maxHeap.empty() || ! waiting.empty() ) {
            
            if( ! maxHeap.empty() ) {
                auto t = maxHeap.top();
                maxHeap.pop();

                if( --t.second )
                    waiting.emplace( t, units + n );

            }
            
            ++units;
            
            while( ! waiting.empty() && waiting.front().second < units ) {
                maxHeap.push( waiting.front().first );
                waiting.pop();
            }
        }
        
        return units;
    }
};
} // namespace