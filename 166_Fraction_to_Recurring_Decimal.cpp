/*
 * Given two longegers representing the numerator and denominator of a fraction, return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 *  Given numerator = 1, denominator = 2, return "0.5".
 *  Given numerator = 2, denominator = 1, return "2".
 *  Given numerator = 2, denominator = 3, return "0.(6)".
 */
#include "gtest/gtest.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// on cygwin, g++ 4.8.3 has some bug on std::to_string(), so
// provide a simple replacer
string to_string(long long n) {
    ostringstream converter;
    converter << n;
    return converter.str();
}

class Solution {
public:
    // NOTE: wrong input is not considered, like @denominator is 0
    string fractionToDecimal(int numerator, int denominator) {
        // NOTE: integer division may overflow. for example, -2147483648/-1 = 2147483648
        // but the largest positive integer is 2147483647
        // using Two’s Complement to represent integer, say the integer is 8-bit
        // then the largest positive integer is 01111111, 127
        // the smallest negative integer is 10000000, -128

        // long on some platform may has 32 bit length;
        // use long long to make sure it's 64 bit
        long long numeratorL = numerator;
        long long denominatorL = denominator;
        bool negative = false;
        if (numeratorL < 0) {
            // use labs()
            // use abs() has problem with -2147483648, even though abs()
            // has a "long abs(long n)" version and we pass it with a long argument
            // update: the reason why abs() fail to convert a long -2147483648 may be
            // I forgot to include <cstdlib> so that g++ uses its own built-in version of abs()
            // which maybe only have abs(int) version...
            // numeratorL = labs(numeratorL);
            numeratorL = -numeratorL;
            negative = !negative;
        }
        if (denominatorL < 0) {
            // denominatorL = labs(denominatorL);
            denominatorL = - denominatorL;
            negative = !negative;
        }

        long long quotient = numeratorL / denominatorL;
        long long remainder = numeratorL % denominatorL;

        if (quotient == 0 && remainder == 0) {
            return "0";
        }

        // result is "part1.part2(part3)"
        long long part1 = quotient;
        long long part2 = 0;
        long long part3 = 0;

        long long position = 1;
        unordered_map<long long, long long> remainderPositionMap;
        remainderPositionMap[remainder] = position;

        long long dividend = remainder * 10;
        vector<long long> quoVector;
        vector<long long>::size_type loopPos = 0;
        while (remainder != 0) {
            quotient = dividend / denominatorL;
            remainder = dividend % denominatorL;
            quoVector.push_back(quotient);
            if (remainderPositionMap[remainder] != 0) {
                loopPos = remainderPositionMap[remainder];
                break;
            } else {
                remainderPositionMap[remainder] = ++position;
            }
            dividend = remainder * 10;
        }

        string result;
        if (negative) {
            result.append("-");
        }
        result.append(to_string(part1)); // to_string() is c++ 11 feature

        auto size = quoVector.size();
        if (size != 0) {
            result.append(".");
        }
        for (vector<long long>::size_type i = 0; i < size; ++i) {
            if (i < loopPos - 1) {
                //part2 = part2*10 + quoVector[i]; // wrong: see 1/90, 0.0(1)
                result.append(to_string(quoVector[i]));
            } else if (i == loopPos - 1){
                //part3 = part3*10 + quoVector[i];
                result.append("(");
                result.append(to_string(quoVector[i]));
            } else {
                result.append(to_string(quoVector[i]));
            }
        }
        
        if (loopPos != 0) {
            result.append(")");
        }

        return result;
    }
};

// tests begin
TEST(Problem166Test, Test1) {
    Solution s;
    EXPECT_EQ("0.5", s.fractionToDecimal(1, 2));
    EXPECT_EQ("2", s.fractionToDecimal(2, 1));
    EXPECT_EQ("0.(6)", s.fractionToDecimal(2, 3));
    // int limits, [-2147483648, 2147483647]
    EXPECT_EQ("2147483648", s.fractionToDecimal(-2147483648, -1));
    EXPECT_EQ("0.1(6)", s.fractionToDecimal(1, 6));
    EXPECT_EQ("0.0(1)", s.fractionToDecimal(1, 90));
    // case with negative input
    EXPECT_EQ("-6.25", s.fractionToDecimal(-50, 8));
    // another good test case
    EXPECT_EQ("0", s.fractionToDecimal(0, -5));
    EXPECT_EQ("-2147483648", s.fractionToDecimal(-2147483648, 1));
}
