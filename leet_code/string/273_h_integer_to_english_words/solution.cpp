/*
https://leetcode.com/problems/integer-to-english-words/
*/

#include <string>

using std::string;

namespace {
/*
N - num

Time O(logN) - log based on 10, output is proportional to the number N of digits in the input.
Space O(1)
*/
class Solution {
public:
    string numberToWords(int num) {
        if( num == 0 )
            return "Zero";

        std::vector< std::string > components;

        if( num / 1'000'000'000 ) {
            components.push_back( toComponent( num / 1'000'000'000 ) );
            components.push_back( "Billion" );
        }

        if( int trio = num / 1'000'000 % 1000; trio > 0 ) {
            components.push_back( toComponent( trio ) );
            components.push_back( "Million" );
        }

        if( int trio = num / 1'000 % 1000; trio > 0 ) {
            components.push_back( toComponent( trio ) );
            components.push_back( "Thousand" );
        }

        if( int trio = num % 1000; trio > 0 ) {
            components.push_back( toComponent( trio ) );
        }

        return concatenate( components );
    }

private:
    string toComponent( int num ) {
        static std::map< int, std::string > simpleNum{
            { 0, "" },
            { 1, "One" },
            { 2, "Two" },
            { 3, "Three" },
            { 4, "Four" },
            { 5, "Five" },
            { 6, "Six" },
            { 7, "Seven" },
            { 8, "Eight" },
            { 9, "Nine" },
            { 10, "Ten" },
            { 11, "Eleven" },
            { 12, "Twelve" },
            { 13, "Thirteen" },
            { 14, "Fourteen" },
            { 15, "Fifteen" },
            { 16, "Sixteen" },
            { 17, "Seventeen" },
            { 18, "Eighteen" },
            { 19, "Nineteen" }
        };

        static std::map< int, std::string > rangeNum {
            { 30, "Twenty" },
            { 40, "Thirty" },
            { 50, "Forty" },
            { 60, "Fifty" },
            { 70, "Sixty" },
            { 80, "Seventy" },
            { 90, "Eighty" },
            { 100, "Ninety" }
        };

        std::vector< std::string > components;

        if( int digit = num / 100; digit > 0 ) {
            components.push_back( simpleNum[ digit ] );
            components.push_back( "Hundred" );
        }

        if( int digits = num % 100; digits >= 20 ) {
            components.push_back( rangeNum.upper_bound( digits )->second );
            if( num % 10 > 0 )
                components.push_back( simpleNum[ num % 10 ] );
        }
        else if( int digits = num % 100; digits > 0 ) {
            components.push_back( simpleNum[ digits ] );
        }

        return concatenate( components );
    }

    std::string concatenate( const std::vector< std::string >& tokens, char del = ' ' ) {
        if( tokens.empty() )
            return {};

        std::string result = *tokens.begin();
        for( auto it = std::next( tokens.begin() ); it != tokens.end(); ++it ) {
            result += del + *it;
        }

        return result;
    }
};
} // namespace

namespace {
/*
Reverse pars using stack

Time O(logN) - log based on 10, output is proportional to the number N of digits in the input.
Space O(logN)
*/
class Solution {
public:
    string numberToWords(int num) {
        if( num == 0 )
            return "Zero";

        std::stack< std::string > tokens;

        int groupId = 0;

        while( num ) {
            int digit1 = num % 10; num /= 10;
            int digit2 = num % 10; num /= 10;
            int digit3 = num % 10; num /= 10;

            if( digit1 || digit2 || digit3 )
                tokens.push( thousands[ groupId ] );

            if( digit2 == 1 ) {
                tokens.push( teens[ digit1 ] );
            }
            else {
                tokens.push( ones[ digit1 ] );
                tokens.push( tens[ digit2 ] );
            }

            if( digit3 > 0 ){
                tokens.push( "Hundred" );
                tokens.push( ones[ digit3 ] );
            }

            ++groupId;
        }

        std::string result;
        while( ! tokens.empty() ) {
            std::string token = tokens.top();
            tokens.pop();
            if( ! token.empty() )
                result += token + " ";
        }
        result.pop_back();

        return result;
    }

private:
    std::vector< std::string > thousands{ "", "Thousand", "Million", "Billion" };
    std::vector< std::string > tens{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    std::vector< std::string > teens{ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    std::vector< std::string > ones{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
};
} // namespace