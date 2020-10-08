/*
https://leetcode.com/problems/implement-queue-using-stacks/
*/

#include <stack>

namespace {
/*
N - number of elements

Time O(1) - amortized
Space O(N)
*/
class MyQueue {
    std::stack< int > input;
    std::stack< int > output;

    void moveElements() {
        while( ! input.empty() ) {
            output.push( input.top() );
            input.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push( x );
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if( output.empty() ) {
            moveElements();
        }

        int value = output.top();
        output.pop();

        return value;
    }
    
    /** Get the front element. */
    int peek() {
        if( output.empty() ) {
            moveElements();
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};
} // namespace
