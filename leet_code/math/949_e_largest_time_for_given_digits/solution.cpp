/*
https://leetcode.com/problems/largest-time-for-given-digits/
*/

#include <vector>

using std::vector;

namespace {
/*
Generete all possbile permutaions, start from min possible. Last valid permutation is answer.

N - size of A

Time O(1)
Space O(1)
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        std::sort( A.begin(), A.end() );
        int maxTime = -1;
        do {
            if( isValid( A ) )
                maxTime = toMinutes( A );
        } while( nextPermutation( A ) );

        return maxTime == -1 ? "" : toString( maxTime );
    }

private:
    bool nextPermutation( std::vector< int >& arr ) {
        int i = arr.size() - 2;
        while( i >= 0 && arr[ i ] >= arr[ i + 1 ] )
            --i;

        if( i >= 0 ) {
            int j = arr.size() - 1;
            while( arr[ i ] >= arr[ j ] )
                --j;

            std::swap( arr[ i ], arr[ j ] );
            std::reverse( arr.begin() + i + 1, arr.end() );
            return true;
        }
        else {
            std::reverse( arr.begin(), arr.end() );
            return false;
        }
    }

    bool isValid( const std::vector< int >& arr ) {
        return ( arr[ 0 ] * 10 + arr[ 1 ] < 24 )
            && ( arr[ 2 ] * 10 + arr[ 3 ] < 60 );
    }

    int toMinutes( const std::vector< int >& arr ) {
        return ( arr[ 0 ] * 10 + arr[ 1 ] ) * 60
            +  ( arr[ 2 ] * 10 + arr[ 3 ] );
    }

    std::string toString( int minutes ) {
        std::ostringstream oss;
        oss << std::setw( 2 ) << std::setfill( '0' ) << ( minutes / 60 )
            << ":"
            << std::setw( 2 ) << std::setfill( '0' ) << ( minutes % 60 );
        return oss.str();
    }
};
} // namespace

namespace {
/*
Solution based on custom pre_permutation doesn't work. 
Previous permutation materials:
https://www.techiedelight.com/std_prev_permutation-overview-implementation/
https://www.geeksforgeeks.org/lexicographically-previous-permutation-in-c/
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        std::sort( std::begin( A ), std::end( A ), std::greater< int >{} );
        do {
            if( isValid( A ) )
                return toString( A );
        } while( prevPermutation( A ) );

        return {};
    }

private:
    bool prevPermutation( std::vector< int >& arr ) {
        int i = arr.size() - 1;
        while( i > 0 && arr[ i - 1 ] <= arr[ i ] )
            --i;

        if( i > 0 ) {
            int j = i;
            while( j < arr.size() && arr[ i - 1 ] >= arr[ j ] )
                ++j;
            --j;

            std::swap( arr[ i - 1 ], arr[ j ] );
            std::reverse( std::begin( arr ) + i, std::end( arr ) );
            return true;
        }
        else {
            std::reverse( std::begin( arr ), std::end( arr ) );
            return false;
        }
    }

    bool isValid( const std::vector< int >& arr ) {
        return ( arr[ 0 ] * 10 + arr[ 1 ] < 24 )
            && ( arr[ 2 ] * 10 + arr[ 3 ] < 60 );
    }

    std::string toString( const std::vector< int >& arr ) {
        std::ostringstream oss;
        oss << arr[ 0 ] << arr[ 1 ] << ":" << arr[ 2 ] << arr[ 3 ];
        return oss.str();
    }
};
} //namespace