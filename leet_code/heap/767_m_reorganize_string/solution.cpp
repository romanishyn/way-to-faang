/*
https://leetcode.com/problems/reorganize-string/
*/

#include <string>
#include <unordered_map>
#include <queue>

using std::string;

namespace {
/*
N - size of S

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    string reorganizeString(string S) {
        std::unordered_map< char, int > charToFrequency;
        for( char c : S )
            ++charToFrequency[ c ];

        using Pair = std::pair< int, char >;
        auto comparator = []( const Pair& lhs, const Pair& rhs ) {
            return lhs.first < rhs.first;
        };
        std::priority_queue< Pair, std::vector< Pair >, decltype( comparator ) > maxHeap( comparator );
        for( auto [ ch, frequency ]: charToFrequency )
            maxHeap.emplace( frequency, ch );

        std::string result;
        Pair prev{ -1, 'a' };
        while( !maxHeap.empty() ) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            result += curr.second;
            --curr.first;
            if( prev.first > 0 )
                maxHeap.push( prev );

            prev = curr;
        }

        return result.size() == S.size() ? result : "";
    }
};
} // namespace