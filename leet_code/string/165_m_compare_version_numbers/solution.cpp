/*
https://leetcode.com/problems/compare-version-numbers/
*/

#include <vector>

namespace {
/*
Split + Parse
Splip both strings by dot and convert to integer
Iterate over the longest array and compare tokens one by one. If one of the arrya is over,
virtually add as many zeros an need to continue the comparison with the longest array. If
two tokens are not equal, return 1 or -1.
If we're here, the version are equal, return 0

N - length of version1
M - length of version2

Time O(N + M)
Space O(N + M)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const auto tokens1 = split( version1 );
        const auto tokens2 = split( version2 );

        int idx = 0;
        while( idx < tokens1.size() || idx < tokens2.size() ) {
            const int num1 = idx < tokens1.size() ? tokens1[ idx ] : 0;
            const int num2 = idx < tokens2.size() ? tokens2[ idx ] : 0;

            if( num1 != num2 )
                return num1 < num2 ? -1 : 1;

            ++idx;
        }

        return 0;
    }

private:
    std::vector< int > split( const std::string& version ) {
        std::vector< int > result;
        std::istringstream iss{ version };
        for( std::string token; std::getline( iss, token, '.' ); ) {
            result.push_back( std::stoi( token ) );
        }
        return result;
    }
};
} // namespace

namespace {
/*
One pass, without extra space

Iterate over the longest version and compare token by token, if one verstion is over,
virtually use zero as token. If tokens are different, return -1 or 1.
Each token convert in interger value, using stream approach.
If we are here, return 0.

N - max length of version

Time O(N)
Space O(1)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(
            int i = 0, j = 0;
            i < version1.size() || j < version2.size();
            ++i, ++j
        ) {
            int num1 = 0;
            int num2 = 0;

            for( ; i < version1.size() && version1[ i ] != '.'; ++i ) {
                num1 *= 10;
                num1 += version1[ i ] - '0';
            }

            for( ; j < version2.size() && version2[ j ] != '.'; ++j ) {
                num2 *= 10;
                num2 += version2[ j ] - '0';
            }

            if( num1 != num2 )
                return num1 < num2 ? -1 : 1;
        }

        return 0;
    }
};
} // namespace

namespace {
/*
Big integer

K - max(version1.size, version2.size)

Time O(K)
Space O(K)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::string token1;
        std::string token2;
        std::istringstream iss1{ version1 };
        std::istringstream iss2{ version2 };

        while( iss1 || iss2 ) {
            token1 = std::getline( iss1, token1, '.' ) ? token1 : "";
            token2 = std::getline( iss2, token2, '.' ) ? token2 : "";

            int ans = compare( token1, token2 );
            if( ans != 0 ) {
                return ans;
            }
        }

        return 0;
    }

private:
    int compare( const std::string& token1, const std::string& token2 ) {
        std::string t1 = token1.substr( std::min( token1.size(), token1.find_first_not_of( '0' ) ) );
        std::string t2 = token2.substr( std::min( token2.size(), token2.find_first_not_of( '0' ) ) );

        if( t1.size() < t2.size() )
            return -1;
        if( t1.size() > t2.size() )
            return 1;
        
        for( int i = 0; i < t1.size(); ++i ) {
            if( t1[ i ] != t2[ i ] )
                return t1[ i ] < t2[ i ] ? -1 : 1;
        }
        
        return 0;
    }
};
} // namespace
