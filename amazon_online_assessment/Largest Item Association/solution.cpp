/*
https://leetcode.com/discuss/interview-question/782606/
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

namespace {
/*
std::unordered_set in graph because there is no info about if pairs are unique
*/
class PairString {
public:
    std::string first;
    std::string second;

    PairString(std::string first, std::string second)
    :   first{ std::move( first ) }
    ,   second{ std::move( second ) }
    {
    }
};

class Solution {
public:
    std::vector< std::string > largestItemAssociation( const std::vector<PairString>& itemAssociation) {
        std::unordered_map< std::string, std::unordered_set< std::string > > graph;
        for( const auto& [first, second] : itemAssociation ) {
            graph[ first ].insert( second );
            graph[ second ].insert( first );
        }

        std::vector< std::string > result;

        std::unordered_set< std::string > seen;

        for( const auto& [ vertex, adjacent ] : graph ) {
            if( ! seen.insert( vertex ).second )
                continue;

            std::vector< std::string > group{ vertex };
            std::stack< std::string > stack;
            stack.push( vertex );

            while( ! stack.empty() ) {
                const auto item = stack.top();
                stack.pop();

                for( const auto& adj : graph[ item ] ) {
                    if( seen.insert( adj ).second ) {
                        stack.push( adj );
                        group.push_back( adj );
                    }
                }
            }

            if( group.size() >= result.size() ) {
                std::sort( begin( group ), end( group ) );

                if( group.size() > result.size() || group < result ) {
                    result = std::move( group );
                }
            }
        }

        return result;
    }
};

int main() {
    using std::vector;

    Solution solution;

    std::vector<PairString> itemAssociation = {
      PairString("item1", "item2"), PairString("item2", "item3"),
      PairString("item4", "item5"), PairString("item6", "item7"),
      PairString("item5", "item6"), PairString("item3", "item7")};

    std::vector<string> expected = {"item1", "item2", "item3", "item4",
                             "item5", "item6", "item7"};
    assert(solution.largestItemAssociation( itemAssociation ) == expected );

  vector<PairString> itemAssociation2 = {PairString("item1", "item2"),
                                         PairString("item3", "item4"),
                                         PairString("item4", "item5")};
  vector<string> expected2 = {"item3", "item4", "item5"};
    assert(solution.largestItemAssociation( itemAssociation2 ) == expected2 );

  vector<PairString> itemAssociation3 = {PairString("item1", "item2"),
                                         PairString("item3", "item4"),
                                         PairString("item5", "item6")};
  vector<string> expected3 = {"item1", "item2"};
    for( auto str : solution.largestItemAssociation( itemAssociation3 ))
        std::cout << str << std::endl;
    std::cout << std::endl;
    assert(solution.largestItemAssociation( itemAssociation3 ) == expected3 );

  vector<PairString> itemAssociation4 = {
      PairString("item1", "item2"), PairString("item2", "item3"),
      PairString("item4", "item5"), PairString("item5", "item6")};
  vector<string> expected4 = {"item1", "item2", "item3"};
    assert(solution.largestItemAssociation( itemAssociation4 ) == expected4 );

    return 0;
}
} // namespace
