/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

// Tag: easy

#include "gtest/gtest.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<string::value_type> stack;

        auto iter = s.begin();
        auto end = s.end();
        while (iter != end) {
            if (isLeft(*iter)) {
                stack.push(*iter);
            } else {
                if (stack.empty() || isRight(stack.top()) || !isMatched(stack.top(), *iter)) {
                    return false;
                } else {
                    stack.pop();
                }
            }
            ++iter;
        }

        if (stack.empty()) {
            return true;
        }
        
        return false;
    }

    bool isLeft(string::value_type ch) const {
        if (ch == '(' || ch == '[' || ch == '{') {
            return true;
        }
        return false;
    }

    bool isRight(string::value_type ch) const {
        return !isLeft(ch);
    }

    bool isMatched(string::value_type ch1, string::value_type ch2) const {
        return (ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') || (ch1 == '{' && ch2 == '}');
    }
};

// Test begin
TEST(Problem20Test, Test1) {
    Solution s;

    // ([{}])
    EXPECT_TRUE(s.isValid("([{}])"));

    // ((()
    EXPECT_FALSE(s.isValid("((()"));

    // (()))
    EXPECT_FALSE(s.isValid("(()))"));

    // ()[]
    EXPECT_TRUE(s.isValid("()[]"));
    
    EXPECT_FALSE(s.isValid("()[]("));

    EXPECT_FALSE(s.isValid("(][)"));
}

