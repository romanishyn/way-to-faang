/*
https://leetcode.com/problems/toeplitz-matrix/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
N - matrix.size
M - matrix[0].size

Time O(N*M)
Space O(1)
*/
	class Solution {
	public:
		bool isToeplitzMatrix(vector<vector<int>>& matrix) {
			const int rows = matrix.size();
			const int cols = matrix[0].size();

			for (int i = 1; i < rows; ++i) {
				for (int j = 1; j < cols; ++j) {
					if (matrix[i - 1][j - 1] != matrix[i][j])
						return false;
				}
			}

			return true;
		}
	};
} // namespace
