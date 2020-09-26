/*
https://leetcode.com/problems/largest-number/
*/

#include <vector>

using std::vector;
using std::string;

namespace {
/*
Pay attention how to compare two strings. This method allows to avoid different edge cases in comparing strings.

N - size of nums

Time O(NlogN), ignore K(length of string) since it is coefficient which is not greater than 10 (count of digits in number)
Space O(N)
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector< std::string > strings = toStrings( nums );

        auto comparator = []( const std::string& s1, const std::string& s2 ){
            return s1 + s2 > s2 + s1;
        };
        std::sort( strings.begin(), strings.end(), comparator );

        if( strings[ 0 ] == "0" && strings.size() > 1 )
            return { "0" };

        std::string result;
        for( const std::string& str : strings )
            result += str;

        return result;
    }

private:
    std::vector< std::string > toStrings( const std::vector< int >& nums ) {
        std::vector< std::string > result;
        for( int num : nums )
            result.push_back( std::to_string( num ) );

        return result;
    }
};
} // namespace