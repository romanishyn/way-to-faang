/*
https://leetcode.com/problems/valid-number/
*/

#include <string>

namespace {
/*
in real interview need ask "What does 'valid number' mean?"
"0.e0" - valid

*/
class Solution {
    enum class Edge {
        Digit,
        Sign,
        Epsilon,
        Blank,
        Dot,
        Other
    };
/*
Digit consumer, the same logic for digits before and after dot. for digits after epsilon another logic
*/
    enum class Vertex {
        Initial = 1,
        NumberConsumer,
        FoundBeginningSign,
        AfterDot, // digit, 
        OnlyDot, // next only digits: .5, .5e+0
        
        
        Point,
        Sign,
        SignEpsilon,
        Epsilon,
        TralingSpace
    };

public:
    bool isNumber(string s) {
        std::unordered_map< Vertex, std::unordered_map< Edge, Vertex > > fsm{
            { Vertex::Initial, {
                { Edge::Blank, Vertex::Initial }
                { Edge::Sign, Vertex::NumberBefore },
                { Edge::Digit, Vertex::NumberBefore },
                { Edge::Point, Vertex::Point } } },
            { Vertex::NumberBefore, {
                { Edge::Digit, Vertex::NumberBefore },
                { Edge::Epsilon, Vertex::Epsilon },
                { Edge::Point, Vertex::Point },
                { Edge::Blank, Vertex::TralingSpace } } },
            { Vertex::NumberAfter, {
                { Edge::Digit, Vertex::NumberAfter },
                { Edge::Epsilon, Vertex::Epsilon },
                { Edge::Blank, Vertex::TralingSpace } } },
            { Vertex::NumberEpsilon, {
                { Edge::Digit, Vertex::NumberEpsilon },
                { Edge::Blank, Vertex::TralingSpace } } },
           { Vertex::Point, {
                { Edge::Digit, Vertex::NumberAfter },
                { Edge::Blank, Vertex::TralingSpace } } },
            { { Edge::Digit, 2 }}
            { { Edge::Digit, 3 } }, // Point
            { { Edge::Digit, 3 }, { Edge::Epsilon, } // Digit after point
            
        };
    }
};
} // namespace

namespace {
class Solution {
public:
    bool isNumber(string s) {
        return false;
    }
};
} // namespace
