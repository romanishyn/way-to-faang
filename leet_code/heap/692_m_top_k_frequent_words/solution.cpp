/*
https://leetcode.com/problems/top-k-frequent-words/
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

using std::vector;
using std::string;

namespace {
/*
Using Heap

N - size of words
K - k top elements

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map< std::string, int > wordFrequency;
        for( const auto& word : words )
            ++wordFrequency[ word ];

        auto comparator = [ &wordFrequency ]( const std::string& lhs, const std::string& rhs ) {
            if( wordFrequency[ lhs ] == wordFrequency[ rhs ] )
                return lhs < rhs;
            else
                return wordFrequency[ lhs ] > wordFrequency[ rhs ];
        };

        std::priority_queue< std::string, std::vector< std::string >, decltype( comparator ) > maxHeap( comparator );
        
        for( auto& [word, _] : wordFrequency ) {
            maxHeap.push( word );
            if( maxHeap.size() > k )
                maxHeap.pop();
        }

        std::vector< std::string > result( k );
        while( k-- > 0 ) {
            result[ k ] = maxHeap.top();
            maxHeap.pop();
        }

        return result;
    }
};
} //namespace


namespace {
/*
QuickSelect + k Sort

N - size of words
K - k top elements

Time O(max(N, KlogK)
Space O(N)
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map< std::string, int > wordFrequency;
        std::vector< std::string > uniqueWords;
        for( const auto& word: words ) {
            auto [it, success] = wordFrequency.try_emplace( word, 0 );
            if( success )
                uniqueWords.push_back( word );

            it->second++;
        }

        auto comparator = [&wordFrequency]( const auto& lhs, const auto& rhs ) {
            if( wordFrequency[ lhs ] == wordFrequency[ rhs ] )
                return lhs < rhs;
            else
                return wordFrequency[ lhs ] > wordFrequency[ rhs ];
        };
        std::nth_element( begin( uniqueWords ), std::next( begin( uniqueWords ), k - 1 ), end( uniqueWords ), comparator );

        std::sort( begin( uniqueWords ), std::next( begin( uniqueWords ), k ), comparator );

        return {  begin( uniqueWords ), std::next( begin( uniqueWords ), k )  };
    }
};
} // namespace
