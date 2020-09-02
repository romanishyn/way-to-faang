/*
https://leetcode.com/problems/read-n-characters-given-read4/
*/

namespace {
/*
Time O(N)
Space O(1)
*/
  // The read4 API is defined in the parent class Reader4.
      int read4(char *buf4);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        const int wordSize{ 4 };
        char word[ wordSize ];
        int write = 0;
        int currRead = 0;

        do {
            currRead = read4( word );
            for( int i = 0; i < currRead && write < n; ++i, ++write )
                buf[ write ] = word[ i ];
        } while( currRead == 4 && write < n );

        return write;
    }
};
} // namespace

namespace {
/*
Time O(N)
Space O(1)
*/

  // The read4 API is defined in the parent class Reader4.
      int read4(char *buf4);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int write = 0;
        int readSize = 0;

        do {
            readSize = read4( buf + write );
            write += readSize;
        } while( write < n && readSize == 4 );

        return std::min( write, n );
    }
};
}