/*
https://leetcode.com/problems/custom-sort-string/
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {
/*
N - order.size
M - s.size

Time O(N+M)
Space O(26)
*/
class Solution {
public:
	string customSortString(string order, string s) {
		std::map< char, int > charCount{};
		for (char ch : s) {
			++charCount[ch];
		}

		std::string result;
		for (char alpha : order) {
			while (charCount[alpha]--)
				result += alpha;
		}

		for (auto[ch, count] : charCount) {
			while (count-- > 0)
				result += ch;
		}

		return result;
	}
};
} // namespace

namespace {
/*
N - order.size
M - s.size

Time O(N+M)
Space O(26)
*/
class Solution {
public:
	string customSortString(string order, string s) {
		std::array< int, 26 > count{};
		for (char ch : s)
			++count[ch - 'a'];

		std::string result;
		for (char alpha : order) {
			result.append(count[alpha - 'a'], alpha);
			count[alpha - 'a'] = 0;
		}

		for (int i = 0; i < count.size(); ++i)
			result.append(count[i], 'a' + i);

		return result;
	}
};
} // namespace
