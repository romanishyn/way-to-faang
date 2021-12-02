/*
https://leetcode.com/problems/valid-word-abbreviation/
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {
/*
N - word.size
M - abbr.size

Time O(min(N,M)) ?
Space O(1)
*/
class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int aIdx = 0;
		int wIdx = 0;
		while (aIdx < abbr.size() && wIdx < word.size()) {
			if (std::isalpha(abbr[aIdx])) {
				if (word[wIdx++] != abbr[aIdx++])
					return false;
			}
			else {
				int num = 0;
				if (abbr[aIdx] == '0')
					return false;

				while (aIdx < abbr.size() && std::isdigit(abbr[aIdx])) {
					num *= 10;
					num += static_cast<int>(abbr[aIdx++] - '0');
				}

				wIdx += num;
			}
		}

		return aIdx == abbr.size() && wIdx == word.size();
	}
};
} // namespace
