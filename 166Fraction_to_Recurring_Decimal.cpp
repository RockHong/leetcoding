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

using namespace std;

// on cygwin, g++ 4.8.3 has some bug on std::to_string(), so
// provide a simple replacer
string to_string(long n) {
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
        long numeratorL = numerator;
        long denominatorL = denominator;
        long quotient = numeratorL / denominatorL;
        long remainder = numeratorL % denominatorL;

        string result;
        result.append(to_string(quotient)); // to_string() is c++ 11 feature

        long i = 1;
        unordered_map<long, long> map;
        vector<long> quoVec;
        vector<long>::size_type loop = 0;
        long dividend = remainder * 10;
        while (remainder != 0) {
            quotient = dividend / denominatorL;
            remainder = dividend % denominatorL;
            quoVec.push_back(quotient);
            if (map[remainder] != 0) {
                loop = map[remainder];
                break;
            } else {
                map[remainder] = i;
            }
            dividend = remainder * 10;
        }

        auto size = quoVec.size();

        long part1 = 0;
        long part2 = 0;
        for (vector<long>::size_type i = 0; i < size; ++i) {
            if (i < loop - 1) {
                part1 = part1*10 + quoVec[i];
            } else {
                part2 = part2*10 + quoVec[i];
            }
        }
        
        if (size != 0) {
            result.append(".");
            if (part1 != 0) {
                result.append(to_string(part1));
            }
        }
        if (loop != 0) {
            result.append("(");
            result.append(to_string(part2));
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
}
