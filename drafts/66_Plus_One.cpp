/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
       vector<int> result;

       if (digits.empty()) {
           result.push_back(1);
           return result;
       }

       if (allNine(digits)) {
           result.insert(result.begin(), digits.size() + 1, 0);
           result[0] = 1;
           return result;
       }

       result = digits;
       int carry = 1;
       auto iter = result.rbegin();
       while(carry == 1) {
           carry = (*iter + carry)/10;
           *iter = (*iter + 1)%10;
           ++iter;
       };

       return result;
    }

    bool allNine(const vector<int> &digits) const {
        auto iter = digits.begin();
        auto end = digits.end();
        while (iter != end) {
            if (*(iter++) != 9) {
                return false;
            }
        }
        
        return true;
    }
};

// tests begin
TEST(Problem66Test, Test1) {
    // [] empty input
    // [0]
    // [1,2]
    // [1,9]
    // [9]
    // [0,9]
