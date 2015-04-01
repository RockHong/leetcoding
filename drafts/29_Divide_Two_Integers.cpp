/*
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == numeric_limits<int>::lowest() && divisor == -1)) {
            return numeric_limits<int>::max();
        }

        if (dividend == 0) {
            return 0;
        }

        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            return -dividend;
        }

        bool positive = true;
        if (dividend < 0 && divisor < 0) {
            dividend = -dividend; // will overflow lowest
            divisor = -divisor;
            positive = true;
        } else if (dividend > 0 && divisor > 0) {
            positive = true;
        } else if (dividend > 0 && divisor < 0) {
            dividend = -dividend;
            divisor = -divisor;
            positive = false;
        } else {
            positive = false;
        }

        int k = 0;
        if (positive) {
        int lower = 0;
        int upper = 1;
        //bool upperFound = true;
        int divisorTmp = divisor;//divisor*1;
        int HALF_MAX = numeric_limits<int>::max() > 1;
        while (dividend - divisorTmp >= 0) {
            //lower++;
            if (divisorTmp <= HALF_MAX) {
                divisorTmp = divisorTmp << 1;
                //lower = upper;
                lower++;
                upper = upper << 1;
            } else {
                //upperFound = false;
                //lower = upper;
                break;
            }
        }
        
        if (lower == 0) {
            k = 0;
        } else {

        k = 1<<lower;
        dividend = dividend - divisor << lower;
        }

            while ((dividend -= divisor) >= 0) {
                k++;
            }
            return k;
        } else {
            while ((dividend += divisor) <= 0) {
                k++;
            }
            return -k;
        }


    }
};

// tests begin
TEST(Problem29Test, Test1) {
    Solution s;

    EXPECT_EQ(0, s.divide(3,9));
    EXPECT_EQ(31, s.divide(63,2));
    EXPECT_EQ(0, s.divide(3,-9));
    EXPECT_EQ(3, s.divide(9,3));
    EXPECT_EQ(2, s.divide(9,4));
    EXPECT_EQ(9, s.divide(9,1));
    EXPECT_EQ(numeric_limits<int>::max(), s.divide(9,0));
    EXPECT_EQ(numeric_limits<int>::max(), s.divide(numeric_limits<int>::lowest(),-1));
    EXPECT_EQ(-3, s.divide(9,-3));
    EXPECT_EQ(-3, s.divide(-9,3));
    EXPECT_EQ(3, s.divide(-9,-3));
    EXPECT_EQ(4, s.divide(-9,-2));
    EXPECT_EQ(-9, s.divide(9,-1));
    EXPECT_EQ(1, s.divide(numeric_limits<int>::max(), numeric_limits<int>::max()));
    EXPECT_EQ(0, s.divide(numeric_limits<int>::max(), numeric_limits<int>::lowest()));
    EXPECT_EQ(-1, s.divide(numeric_limits<int>::lowest(), numeric_limits<int>::max()));
    EXPECT_EQ(1, s.divide(numeric_limits<int>::lowest(), numeric_limits<int>::lowest()));
    EXPECT_EQ(1, s.divide(numeric_limits<int>::max(), numeric_limits<int>::max()-1));
    EXPECT_EQ(-1, s.divide(numeric_limits<int>::max(), numeric_limits<int>::lowest()+1));
    EXPECT_EQ(1, s.divide(numeric_limits<int>::lowest(), numeric_limits<int>::lowest()+1));
}
