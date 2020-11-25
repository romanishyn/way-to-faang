/*
https://leetcode.com/discuss/interview-question/699973/
*/

#include <vector>
#include <queue>

namespace {
/*
0 - enter
1 - exit

N - size of times

Time O(N)
Space O(N)
*/
class Solution {
public:
    std::vector< int > run(
        const std::vector< int >& times,
        const std::vector< int >& directions
    ) {
        const int size = times.size();
        std::queue< int > entry;
        std::queue< int > exit;
        for( int i = 0; i < size; ++i ) {
            if( directions[ i ] == 1 )
                exit.push( i );
            else
                entry.push( i );
        }

        std::vector< int > result( size );

        int prev = 1;
        int currTime = 0;
        int lastTime = 0;

        while( ! entry.empty() && ! exit.empty() ) {
            const int entryTime = std::max( currTime, times[ entry.front() ] );
            const int exitTime = std::max( currTime, times[ exit.front() ] );

            if( entryTime == exitTime ) {
                if( currTime - lastTime > 1 || prev == 1 ) {
                    result[ exit.front() ] = exitTime;
                    exit.pop();
                    lastTime = currTime = exitTime;
                    prev = 1;
                }
                else {
                    result[ entry.front() ] = entryTime;
                    entry.pop();
                    lastTime = currTime = entryTime;
                    prev = 0;
                }
            }
            else if( entryTime < exitTime ) {
                    result[ entry.front() ] = entryTime;
                    entry.pop();
                    lastTime = currTime = entryTime;
                    prev = 0;
            }
            else {
                    result[ exit.front() ] = exitTime;
                    exit.pop();
                    lastTime = currTime = exitTime;
                    prev = 1;
            }

            ++currTime;
        }

        while( ! entry.empty() ) {
            currTime = std::max( currTime, times[ entry.front() ] );
            result[ entry.front() ] = currTime;
            entry.pop();
            ++currTime;
        }

        while( ! exit.empty() ) {
            currTime = std::max( currTime, times[ exit.front() ] );
            result[ exit.front() ] = currTime;
            exit.pop();
            ++currTime;
        }

        return result;
    }
};

int main() {
    auto test = [i=1](Solution &sol, const vector<int> &t, const vector<int> &dir,
              const vector<int> &expected) mutable {
      cout << "Run test case " << i++ << endl;
      auto res = sol.run(t, dir);
      for (auto &item : res)
        cout << item << " ";
      cout << endl;
      for (auto &item : expected)
        cout << item << " ";
      cout << endl;

      assert(res == expected);
      cout << "Success!" << endl;
    };

    Solution sol;
    vector<int> t = {0, 0, 1, 5};
    vector<int> dir = {0, 1, 1, 0};
    vector<int> expected = {2, 0, 1, 5};
    test(sol, t, dir, expected);

    vector<int> t2 = {1, 2, 4};
    vector<int> dir2 = {0, 1, 1};
    vector<int> expected2 = {1, 2, 4};
    test(sol, t2, dir2, expected2);

    vector<int> t3 = {1, 1};
    vector<int> dir3 = {1, 1};
    vector<int> expected3 = {1, 2};
    test(sol, t3, dir3, expected3);

    vector<int> t4 = {1, 1, 3, 3, 4, 5, 6, 7, 7};
    vector<int> dir4 = {1, 1, 0, 0, 0, 1, 1, 1, 1};
    vector<int> expected4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    test(sol, t4, dir4, expected4);

    return 0;
}
} // namespace
