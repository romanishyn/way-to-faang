/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
N - size of heights

Time O(N)
Space O(1)
*/
class Solution {
public:
	vector<int> findBuildings(vector<int>& heights) {
		const int size = heights.size();
		std::vector< int > result{ size - 1 };
		int maxHight = heights.back();

		for (int i = heights.size() - 2; i >= 0; --i) {
			if (heights[i] > maxHight) {
				result.push_back(i);
				maxHight = heights[i];
			}
		}

		std::reverse(begin(result), end(result));

		return result;
	}
};
} // namespace

namespace {
/*
not optimal
monotonic stack

N - size of heights

Time O(N)
Space O(N)
*/
class Solution {
public:
	vector<int> findBuildings(vector<int>& heights) {
		std::vector< int > stack;
		for (int i = 0; i < heights.size(); ++i) {
			while (!stack.empty() && heights[stack.back()] <= heights[i])
				stack.pop_back();

			stack.push_back(i);
		}

		return stack;
	}
};
} // namespace
