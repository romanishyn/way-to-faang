/*
https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
*/

namespace {
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;
        while( bufIdx < n ) {
            if( ! hasNext() )
                readData();

            if( ! hasNext() )
                break;

            buf[ bufIdx++ ] = next();
        }

        return bufIdx;
    }

private:
    bool hasNext() const {
        return idx != size;
    }

    void readData() {
        size = read4( buffer );
        idx = 0;
    }

    char next() {
        return buffer[ idx++ ];
    }

private:
    char buffer[ 4 ] = {};
    int size = 0;
    int idx = 0;
};
} // namespace

namespace {
/*
Optimisation: read data to buf if it is possible
*/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;

        while( bufIdx < n ) {
            if( hasNext() ) {
                buf[ bufIdx++ ] = next();
            }
            else {
                if( n - bufIdx >= 4 ) {
                    int readCount = read4( buf + bufIdx );
                    bufIdx += readCount;
                    if( readCount < 4 )
                        break; // EOF
                }
                else {
                    readData();
                    if( ! hasNext() )
                        break; // EOF
                }
            }
        }

        return bufIdx;
    }
    
private:
    bool hasNext() const {
        return idx != size;
    }

    char next() {
        return buffer[ idx++ ];
    }

    void readData() {
        size = read4( buffer );
        idx = 0;
    }

private:
    char buffer[ 4 ] = {};
    int size = 0;
    int idx = 0;
};
} // namespace
