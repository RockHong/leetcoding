/*
 * Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

// Tag: easy

#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int reverse(int x) {
       int reverse = 0;
       bool negative = x < 0;
       x = std::abs(x);

       // O(n)
       while (x > 0) {
           int remainder = x % 10;
           x = x/10;
           if (willMultiplicationOverflow(reverse, 10)) {
               return 0;
           }
           reverse *= 10;
           int origin = reverse;
           reverse += remainder;
           if (isAdditionOverflow(reverse, origin)) {
               return 0;
           }
       }

       if (negative) {
           reverse = -reverse;
       }

       return reverse;
    }

    // detect overflow
    // http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
    // http://www.cplusplus.com/articles/DE18T05o/
    bool isAdditionOverflow(int result, int origin) {
        if (result < origin) {
            return true;
        }
        return false;
    }

    // for multiplication you can not detect overflow after operation is done
    // for example, 964632435*10 will overflow, and its result is 1056389758
    // but passing result = 1056389758, origin = 964632435 to isAdditionOverflow() will return false, which is not true
    bool willMultiplicationOverflow(int a, int b) {
        int c = numeric_limits<int>::max()/b;
        if (c < a) {
            return true;
        }
        return false;
    }

};

// tests begin
TEST(Problem7Test, Test1) {
    Solution s;
    int x = 0;

    //123
    x = 123;
    EXPECT_EQ(321, s.reverse(x));
    //-123
    x = -123;
    EXPECT_EQ(-321, s.reverse(x));
    //1
    x = 1;
    EXPECT_EQ(1, s.reverse(x));
    //0
    x = 0;
    EXPECT_EQ(0, s.reverse(x));
    //10
    x = 10;
    EXPECT_EQ(1, s.reverse(x));
    // Lesson: consider overflow when operate numbers
    cout << numeric_limits<int>::max(); //2147483647, reverse by javascript, '2147483647'.split("").reverse().join("")
    x = 1463847413;
    EXPECT_EQ(0, s.reverse(x));
    x = 1534236469;
    EXPECT_EQ(0, s.reverse(x));
}
