/*
https://leetcode.com/problems/partition-labels/
*/

#include <array>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::string;

namespace {
/*
Using Sliding Window approach, determin if in current string each letter appears only in this window.
To to this, we can keep track of all unique letters in window and how many appears of lettera are exhaused.
When size of unique letters and number of exhauseted letters equals then add size of window to the result.

N - size of S

Time O(N)
Space O(1), size of each container less than 26
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::unordered_map< char, int > charToFrequency;
        for( char c : S )
            ++charToFrequency[ c ];

        std::vector< int > result;

        int counter = 0;
        std::unordered_set< char > uniqueChar;
        int left = 0;
        for( int right = 0; right < S.size(); ++right ) {
            const char rightChar = S[ right ];
            --charToFrequency[ rightChar ];
            uniqueChar.insert( rightChar );

            if( charToFrequency[ rightChar ] == 0 )
                ++counter;

            if( uniqueChar.size() == counter ) {
                result.push_back( right - left + 1 );
                left = right + 1;
                counter = 0;
                uniqueChar.clear();
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
Greedy approach
1. iterate the string and recort the last index of each letter
2. using pointer to recort the end of current sub-string

N - length of S

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        const char size = S.size();

        std::array< char, 26 > lastPosition;
        for( int i = 0; i < size; ++i )
            lastPosition[ S[ i ] - 'a' ] = i;

        std::vector< int > result;

        int startWindow = 0;
        int endWindow = 0;
        for( int i = 0; i < size; ++i ) {
            endWindow = std::max( endWindow, static_cast< int >( lastPosition[ S[ i ] - 'a' ] ) );
            if( endWindow == i ) {
                result.push_back( endWindow - startWindow + 1 );
                startWindow = i + 1;
            }
        }

        return result;
    }
};
} //namespace