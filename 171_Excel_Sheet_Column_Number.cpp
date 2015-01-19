/*
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 */

#include <string>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    // TODO: verify input. lower case? not alphabeta?
    int titleToNumber(string s) {
        int sum = 0;
        const int a = static_cast<int>('A');

        auto iter = s.begin();
        while(iter != s.end()) {
            sum = sum*26 + static_cast<int>(*(iter++)) - a + 1;
        }
        return sum;
    }
};

// tests begin
TEST(Problem172Test, Test1) {
    Solution s;
    EXPECT_EQ(28, s.titleToNumber("AB"));
}
