// https://leetcode.com/problems/find-peak-element/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

namespace {
/*
N - nums.size

Time O(logN)
Space O(1)
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int ans = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == 0 || nums[mid - 1] < nums[mid]) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return ans;
	}
};
} // namespace
