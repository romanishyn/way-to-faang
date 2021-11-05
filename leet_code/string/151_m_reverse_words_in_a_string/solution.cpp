/*
https://leetcode.com/problems/reverse-words-in-a-string/
*/

namespace {
/*
N - s.size

Time O(N)
Space O(N)
*/
class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss{ s };
        std::stack< std::string > stack;

        std::string word;
        while( std::getline( ss, word, ' ' ) ) {
            if( ! word.empty() )
                stack.push( std::move( word ) );
            
        }

        std::string result = stack.top();
        stack.pop();

        while( ! stack.empty() ) {
            result += " ";
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};
} // namespace

namespace {
/*
N - s.size

Time O(N)
Space O(1)
*/
class Solution {
public:
    string reverseWords(string s) {
        std::reverse( s.begin(), s.end() );

        const int size = s.size();
        int read = 0;
        int write = 0;

        while( read < size ) {
            if( s[ read ] != ' ' ) {
                if( write )
                    s[ write++ ] = ' ';

                int startWrite = write;

                while( read < size && s[ read ] != ' ' )
                    s[ write++ ] = s[ read++ ];

                std::reverse( s.begin() + startWrite, s.begin() + write );
            }
            else
                ++read;
        }

        s.resize( write );

        return s;
    }
};
} // namespace