/*

What is?
 1000001
 1262
 1272

 1000001 -> 0
 1262 -> 3
 1272 -> 2

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


 How many different ways are there to decode this string

 You can use memoization with the recursive approach

 --------------------------------------------------------------------------

 bool isNumber( char x, char y ) {
  return ( '1' == x )
    ||   ( '2' == x && ( y <= '6' ) );
}

int decodeVariations( const string& S, int idx, vector< int >& memo )
{
  if( idx == S.size() )
    return 1;
  if( S[ idx ] == '0' )
    return 0;

  if( memo[ idx ] != -1 )
    return memo[ idx ];

  int result = 0;
  result += decodeVariations(S, idx + 1, memo );

  if( idx <= S.size() - 2 && isNumber( S[ idx ], S[ idx + 1] ) )
    result += decodeVariations(S, idx + 2, memo );

  memo[ idx ] = result;

  return result;
}

int decodeVariations(const string& S)
{
  std::vector< int > memo( S.size(), - 1);

	return decodeVariations( S, 0, memo );
}

 --------------------------------------------------------------------------

A concise dp solution
 int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}
*/

--------------------------------------------------------------------------