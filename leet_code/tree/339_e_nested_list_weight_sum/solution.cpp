/*
https://leetcode.com/problems/nested-list-weight-sum/
*/

#include <vector>

using std::vector;

namespace {
  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();

      // Constructor initializes a single integer.
      NestedInteger(int value);

      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;

      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;

      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);

      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);

      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
} // namespace

namespace {
/*
N - number of nested elemenets
D - maximum level of nesting in the input

Time O(N)
Space O(D)
*/
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum( nestedList, 1 );
    }

private:
    int depthSum( const vector<NestedInteger>& nestedList, int depth ) {
        int result = 0;
        for( const auto& list : nestedList ) {
            if( list.isInteger() ) {
                result += list.getInteger() * depth;
            }
            else {
                result += depthSum( list.getList(), depth + 1 );
            }
            
        }

        return result;
    }
};
} // namespace

namespace {
/*
BFS

N - number of nested elemenets
D - maximum level of nesting in the input

Time O(N)
Space O(N)
*/
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        std::queue< vector<NestedInteger> > todo;
        todo.push( nestedList );

        int result = 0;
        int level = 1;
        while( ! todo.empty() ) {
            const int levelSize = todo.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto list = todo.front();
                todo.pop();

                for( const auto& val : list ) {
                    if( val.isInteger() ) {
                        result += val.getInteger() * level;
                    }
                    else {
                        todo.push( val.getList() );
                    }
                }
            }

            ++level;
        }

        return result;
    }
};
} // namespace

namespace {
/*
DFS

N - number of nested elemenets
D - maximum level of nesting in the input

Time O(N)
Space O(D)
*/
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        std::stack< std::pair< vector<NestedInteger>, int > > todo;
        todo.emplace( nestedList, 1 );

        int result = 0;

        while( ! todo.empty () ) {
            auto [list, depth] = todo.top();
            todo.pop();

            for( const auto& val : list ) {
                if( val.isInteger() ) {
                    result += val.getInteger() * depth;
                }
                else {
                    todo.emplace( val.getList(), depth + 1 );
                }
            }
        }

        return result;
    }
};
} // namespace