/*
https://leetcode.com/problems/maximum-swap/
*/

#include <string>
#include <array>

namespace {
/*
Store right most index of each digit

N - number of digits, log10(num)

Time O(N)
Space O(10) -> O(1)
*/
class Solution {
public:
    int maximumSwap(int num) {
        std::string numStr = std::to_string( num );
        std::unordered_map< char, int > rightMostPos;

        for( int i = 0; i < numStr.size(); ++i ) {
            rightMostPos.insert_or_assign( numStr[ i ], i );
        }

        for( int i = 0; i < numStr.size(); ++i ) {
            for( char ch = '9'; ch > numStr[ i ]; --ch ) {
                auto it = rightMostPos.find( ch );
                if( it != rightMostPos.end() && it->second > i ) {
                    std::swap( numStr[ i ], numStr[ it->second ] );
                    return std::stoi( numStr );
                }
            }
        }

        return std::stoi( numStr );
    }
};
} // namespace

namespace {
/*
To understand solution need to draw diagram of gitits

N - number of digits

Time O(N)
Space O(N)
*/
class Solution {
public:
    int maximumSwap(int num) {
        int maxDigit = -1;
        int maxDigitIdx = -1;

        int leftDigitIdx = -1;
        int rightDigitIdx = -1;

        std::string numStr = std::to_string( num );
        for( int i = numStr.size() - 1; i >= 0; --i ) {
            if( numStr[ i ] > maxDigit ) {
                maxDigit = numStr[ i ];
                maxDigitIdx = i;
                continue;
            }

            if( numStr[ i ] < maxDigit ) {
                leftDigitIdx = i;
                rightDigitIdx = maxDigitIdx;
            }
        }

        if( leftDigitIdx == rightDigitIdx ) // nothing changed. sequence of digits is increasing from right to left
            return num;

        std::swap( numStr[ leftDigitIdx ], numStr[ rightDigitIdx ] );
        return std::stoi( numStr );
    }
};
} // namespace

namespace {
/*
not optimal
based on idea of monotonic stack, from right to left

Time O(N)
Space O(N) or O(10), since stack won't have more than 10 digits
*/
class Solution {
public:
    int maximumSwap(int num) {
        auto str = std::to_string( num );

        std::stack< std::pair< char, int > > stack;

        for( int i = str.size() - 1; i >= 0; --i ) {
            if( stack.empty() || str[ i ] > stack.top().first )
                stack.emplace( str[ i ], i );
        }

        for( int i = 0; i < str.size(); ++i ) {
            if( str[ i ] < stack.top().first ) {
                std::swap( str[ i ], str[ stack.top().second ] );
                break;
            }

            if( stack.top().second == i )
                stack.pop();
        }

        return std::stoi( str );
    }
};
} // namespace