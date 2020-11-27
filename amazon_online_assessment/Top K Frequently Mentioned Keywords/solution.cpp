/*
https://leetcode.com/discuss/interview-question/542597/
similar problem: https://leetcode.com/problems/top-k-frequent-words/
*/

namespace {
/*
Time O(NlogN)
Space O(N)
*/
class Solution  {
private:
    class TextIterator {
        std::string text;
        int idx = 0;

        void goToNextLetter() {
            while( isValid() && ! std::isalpha( text[ idx ] ) ) {
                ++idx;
            }
        }

    public:
        TextIterator( std::string text )
        :   text{ std::move( text ) }
        {
            goToNextLetter();
        }

        bool isValid() const {
            return idx < text.size();
        }

        std::string next() {
            std::string word;

            while( isValid() && std::isalpha( text[ idx ] ) ) {
                word += text[ idx ];
                ++idx;
            }
            goToNextLetter();

            return word;
        }
    };

public:

    std::vector< std::string > topK( int k, const std::vector< std::string >& keywords, const std::vector< std::string >& reviews ) {
        std::unordered_set< std::string > keywordsSet( begin( keywords ), end( keywords ) );
        std::unordered_map< std::string, int > wordFrequency;

        for( const auto& review : reviews ) {
            TextIterator iterator{ review };
            std::unordered_set< std::string > words;
            while( iterator.isValid () ) {
                auto word = iterator.next();
                std::transform( begin( word ), end( word ), begin( word ), ::tolower );
                if( keywordsSet.count( word ) ) {
                    words.insert( std::move( word ) );
                }
            }

            for( auto& word : words ) {
                ++wordFrequency[ word ];
            }
        }

        // operator <
        auto comparator = [ &wordFrequency ]( const auto& lhs, const auto& rhs ) {
            if( wordFrequency[ lhs ] == wordFrequency[ rhs ] )
                return lhs > rhs;
            else
                return wordFrequency[ lhs ] < wordFrequency[ rhs ];
        };

        /*
        Time O(NlogK)
        if( heap.size > k )
            heap.pop
        */
        std::priority_queue< std::string, std::vector< std::string >, decltype( comparator ) > maxHeap( comparator );
        for( const auto& [word, _] : wordFrequency )
            maxHeap.push( word );

        std::vector< std::string > result;
        while( k-- > 0 && ! maxHeap.empty() ) {
            result.push_back( maxHeap.top() );
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution soluiton;
    std::cout << ( std::string( "stall" ) < std::string( "foorball" ) ) << std::endl;
    int k = 3;
    std::vector< std::string > keywords{ "stall","market","football", "four" };
    std::vector< std::string > reviews{
        "Football is a game, which four I like!",
        "I go to the market and buy sweets from the market stall football, four",
        "I love watching football matches four from stall",
        "I opened a four stall" ,
        "four Four?"};

    std::cout << "Expected : " << "four, football, stall" << std::endl;
    for( auto str : soluiton.topK( k, keywords, reviews ) )
        std::cout << str << ", ";
    std::cout << std::endl;

    return 0;
}
} // namespace
