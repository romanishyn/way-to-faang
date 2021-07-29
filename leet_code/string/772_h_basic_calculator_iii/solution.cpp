/*
https://leetcode.com/problems/basic-calculator-iii/
*/

namespace {
class Solution {
public:
    int calculate(string s) {
        const std::string equation = toRPN( s );
        return evaluateRPN( equation );
    }

private:
    int evaluateRPN( const std::string& str ) {
        std::stack< int > stack;
        int num = 0;
        for( int i = 0; i < str.size(); ++i ) {
            const char currChar = str[ i ];
            if( std::isdigit( currChar ) ) {
                num *= 10;
                num += currCahr - '0';
            }
            else {
                const int rightOperand = stack.top();
                stack.pop();
                const int leftOperand = stack.top();
                stack.pop();
                
                int res = 0;
                switch( currChar ) {
                    case '^':
                        res = std::pow( leftOperand, rightOperand );
                        break;
                    case '*':
                        res = leftOperand * rightOperand;
                        break;
                    case '/':
                        res = leftOperand / rightOperand;
                        break;
                    case '+':
                        res = leftOperand + rightOperand;
                        break;
                    case '-':
                        res = leftOperand - rightOperand;
                        break;
                    default:
                        //unreachble code
                        break;
                }
                stack.push( res );
            }
        }

        return stack.top();
    }

    std::string toRPN( const std::string& str ) {
        std::stack< char > operators;
        std::string result;

        for( int i = 0; i < str.size(); ++i ) {
            if( str[ i ] == ' ' )
                continue;

            const char currChar = str[ i ];
            if( currChar == '(' ) {
                operators.push( currChar );
            }
            else if( currChar == ')' ) {
                while( operators.top() != '(' ) {
                    result.push_back( operators.top() );
                    operators.pop();
                }
                operators.pop(); // remove '('
            }
            else if( std::isdigit( currChar ) ) {
                result.push_back( currChar );
            }
            else {
                while( ! operators.empty() && getPriority( currChar ) <= getPriority( operators.top() ) ) {
                    result.push_back( operators.top() );
                    operators.pop();
                }
                operators.push( currChar );
            }
        }

        while( ! operators.empty() ) {
            result.push_back( operators.top() );
            operators.pop();
        }

        return result;
    }

    int getPriority( char ch ) const {
        switch( ch ) {
            case '^':
                return 3;
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                //unreachable code, or ch equals '('
                return 0;
        }
    }
};
} // namespace