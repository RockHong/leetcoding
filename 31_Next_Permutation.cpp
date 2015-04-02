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
#include <algorithm> // reverse
#include <utility> // swap
#include <cstdlib>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) {
            return;
        }

        auto pos1 = findSwitchPos1(num);
        if (pos1 == num.end()) {
            std::reverse(num.begin(), num.end());
        } else {
            // http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
            // 1) Find the largest index k such that a[k] < a[k + 1]. 
            // 2) Find the largest index l greater than k such that a[k] < a[l].
            // 3) Swap the value of a[k] with that of a[l].
            // 4) Reverse the sequence from a[k + 1] up to and including the final element a[n].
            auto pos2 = findSwitchPos2(num, pos1);
            std::swap(*pos1, *pos2);
            std::reverse(pos1+1, num.end());
        }
    }

    vector<int>::iterator findSwitchPos1(vector<int> &num) {
        auto iter = num.rbegin();
        while (iter + 1 != num.rend()) {
            if (*iter > *(iter+1)) {
                return (iter+1).base() - 1; // convert r-iter to iter
            }
            ++iter;
        }
        return num.end();
    }

    vector<int>::iterator findSwitchPos2(vector<int> &num, vector<int>::iterator pos1) {
        auto iter = num.rbegin();
        while (iter != num.rend()) {
            if (*iter > *pos1) {
                return iter.base() - 1;
            }
            ++iter;
        }
        std::cerr <<"error happens" <<endl;
        std::exit(1);
        return num.end();
    }
};

// tests begin
TEST(Problem31Test, Test1) {
    Solution s;
    vector<int> input;

    input = {1,2,3};
    s.nextPermutation(input);
    EXPECT_TRUE(input == vector<int>({1,3,2}));

    input = {1,3,2};
    s.nextPermutation(input);
    EXPECT_TRUE(input == vector<int>({2,1,3}));

    input = {2,3,3};
    s.nextPermutation(input);
    EXPECT_TRUE(input == vector<int>({3,2,3}));

    input = {3,2,1};
    s.nextPermutation(input);
    EXPECT_TRUE(input == vector<int>({1,2,3}));

    input = {1,4,3,2};
    s.nextPermutation(input);
    EXPECT_TRUE(input == vector<int>({2,1,3,4}));
}
