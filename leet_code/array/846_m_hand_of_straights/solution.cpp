/*
https://leetcode.com/problems/hand-of-straights/
*/

#include <vector>
#include <map>

using std::vector;

namespace {
/*
N - size of hand

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if( hand.size() % W != 0 )
            return false;
        
        std::map< int, int > valToFreq;
        for( int val : hand )
            ++valToFreq[ val ];

        while( ! valToFreq.empty() ) {
            const int startVal = valToFreq.begin()->first;
            for( int i = startVal; i < startVal + W; ++i ) {
                auto it = valToFreq.find( i );
                if( it == valToFreq.end() )
                    return false;

                if( --it->second == 0 )
                    valToFreq.erase( it );
            }
        }

        return true;
    }
};
} // namespace
