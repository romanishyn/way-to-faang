/*
https://leetcode.com/problems/first-bad-version/
*/

namespace {
/*
Time O(logN)
Space O(1)
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int badVersion = 1;
        int left = 1;
        int right = n;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;
            if( isBadVersion( mid ) ) {
                badVersion = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return badVersion;
    }
};
} // namespace
