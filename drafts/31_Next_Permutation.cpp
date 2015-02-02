/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    }
};

// tests begin
TEST(Problem31Test, Test1) {
    Solution s;

    // 1321, 13x, 1x, 2, 2113
    // 1321, 21 fail, 32 fail, 13 ok; now insertion sort,1231, 1213, 1123; find the smallest bigger, 2113;
    // 4321, 21 no, 32 no, 43 no; now sort;
    // 1231, 32 no, 23 ok; 1321;
    // 1231, 12x, 1321
    // 2321, 3221, 3212, 3122
    // 1123 1132
    // 1032 1230

    // way2
    // use bt??
}
