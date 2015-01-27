/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        auto iter = tokens.rbegin();
        auto end = tokens.rend();

        while (iter != end) {
            
        }
    }
private:
    stack<string> _operands;
    stack<string> _operators;
};

// tests begins
TEST(Problem150Test, Test1) {
    Solution s;

    vector<string> v;

    v = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(9, s.evalRPN(v));

    v = {"4", "13", "5", "/", "+"};
    EXPECT_EQ(6, s.evalRPN(v));
}
