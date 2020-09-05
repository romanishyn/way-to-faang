/*
https://leetcode.com/problems/rearrange-string-k-distance-apart/
*/

#include <string>
#include <queue>

using std::string;

namespace {
/*
N - size of s

Time O(NlogN)
Space O(N)
*/
class Solution {
    struct CharInfo {
        char data{ 'a' };
        int counter{ 0 };
        int lastPosition{ -1 };

        bool operator < ( const CharInfo& charInfo ) const {
            return counter < charInfo.counter;
        }
    };

public:
    string rearrangeString(string s, int k) {
        std::unordered_map< char, CharInfo > charInfos;
        for( char c : s ) {
            auto& info = charInfos[ c ];
            info.data = c;
            ++info.counter;
        }

        std::priority_queue< CharInfo, std::vector< CharInfo > > maxHeap;
        std::queue< CharInfo > todo;

        for( auto [_, info ] : charInfos )
            maxHeap.push( info );

        std::string result;
        while( ! maxHeap.empty() ) {
            auto info = maxHeap.top();
            maxHeap.pop();

            result += info.data;
            --info.counter;
            info.lastPosition = result.size();
            if( info.counter > 0 )
                todo.push( info );

            if( ! todo.empty() && (int)result.size() - todo.front().lastPosition >= k - 1 ) {
                maxHeap.push( todo.front() );
                todo.pop();
            }
        }

        return result.size() == s.size() ? result : "";
    }
};
} // namespace

namespace {
/*
N - size of s

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    string rearrangeString(string s, int k) {
        std::unordered_map< char, int > charToFrequency;
        for( char c : s )
            ++charToFrequency[ c ];

        using Pair = std::pair< char, int >;
        auto comparator = []( const Pair& lhs, const Pair& rhs ) {
            return lhs.second < rhs.second;
        };
        std::priority_queue< Pair, std::vector< Pair >, decltype( comparator ) > maxHeap( comparator );
        for( Pair entry : charToFrequency )
            maxHeap.push( entry );

        std::string result;

        std::queue< Pair > todo;
        while( ! maxHeap.empty() ) {
            auto currEntry = maxHeap.top();
            maxHeap.pop();

            result += currEntry.first;
            --currEntry.second;
            todo.push( currEntry );

            if( todo.size() >= k ) {
                auto entry = todo.front();
                todo.pop();

                if( entry.second > 0 )
                    maxHeap.push( entry );
            }
        }

        return result.size() == s.size() ? result : "";
    }
};
} // namespace