#include <iostream>

#include "leet_code/dynamic_programming/139_m_word_break/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>


int main()
{
    Solution solution;

    std::string s = "applepenapple";
    vector<string> wordDict = { "apple", "pen" };

    std::cout << "Result: " << std::boolalpha << solution.wordBreak( s, wordDict ) << std::endl;

    return 0;
}

