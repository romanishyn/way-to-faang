/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {
/*
Stack solution

N - s.size
D - number of duplicates

Time O(N)
Space O(N-D)
*/
class Solution {
public:
	string removeDuplicates(string s) {
		std::string result;
		for (char ch : s) {
			if (result.empty() || result.back() != ch)
				result += ch;
			else
				result.pop_back();
		}
		return result;
	}
};
} // namespace

namespace {
/*
Two pointers solution

N - s.size
D - number of duplicates

Time O(N)
Space O(N-D)
*/
class Solution {
public:
	string removeDuplicates(string s) {
		int write = 0;
		for (int read = 0; read < s.size(); ++read) {
			if (write == 0 || s[write - 1] != s[read])
				s[write++] = s[read];
			else
				--write;
		}

		return s.substr(0, write);
	}
};
} // namespace
