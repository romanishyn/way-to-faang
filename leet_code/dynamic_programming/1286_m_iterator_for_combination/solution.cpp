/*
https://leetcode.com/problems/iterator-for-combination/
*/

#include <queue>
#include <string>

namespace {
/*
Using backtracking generate all combinations
*/
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        std::string path;
        generateCombinations( characters, 0, combinationLength, path );
    }

    string next() {
        auto combination = m_combinations.front();
        m_combinations.pop();
        return combination;
    }

    bool hasNext() {
        return !m_combinations.empty();
    }

private:
    void generateCombinations( const std::string& characters, int startIdx, int length, std::string& path ) {
        if( length == 0 ) {
            m_combinations.push( path );
            return;
        }

        for( int i = startIdx; i <= characters.size() - length; ++i ) {
            path.push_back( characters[ i ] );
            generateCombinations( characters, i + 1, length - 1, path );
            path.pop_back();
        }
    }
private:
    std::queue< std::string > m_combinations;
};
} // namespace

namespace {
    // TODO: implement  using bitmanipulation
}