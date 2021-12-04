/*
https://leetcode.com/problems/cutting-ribbons/
*/

#include <vector>
#inlude <stack>
#include <string>

using std::string;
using std::vector;

namespace {
/*
N - ribbons.size

Time O(NlogN)
Space O(1)
*/
class Solution {
public:
	int maxLength(vector<int>& ribbons, int k) {
		int left = 1;
		int right = *std::max_element(begin(ribbons), end(ribbons));
		int ans = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (canCut(ribbons, mid, k)) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return ans;
	}

private:
	bool canCut(const std::vector< int > & ribbons, int length, int k) {
		int count = 0;
		for (int ribbon : ribbons) {
			count += ribbon / length;
		}
		return count >= k;
	}
};
} // namespace
