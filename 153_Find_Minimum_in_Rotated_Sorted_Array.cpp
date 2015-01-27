/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // assure @num is not empty
    int findMin(vector<int> &num) {
        if (num.size() == 1) {
            return num[0];
        }

        if (num.size() == 2) {
            return num[0] < num[1] ? num[0] : num[1];
        }

        int left = 0;
        int right = num.size() - 1;
        int mid;
        bool isShifted = false;
        while (isShifted = shifted(num, left, right)) {
            if (right - left + 1 == 3) {
                break;
            }

            mid = (left + right)/2;
            if (shifted(num, left, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        assert(right - left + 1 == 3 || !isShifted);

        if (!isShifted) {
            return num[left] < num[right] ? num[left] : num[right];
        }

        // otherwise, find min in three
        int min = num[left];
        if (num[(left + right)/2] < min) {
            min = num[(left + right)/2];
        }
        if (num[right] < min) {
            min = num[right];
        }
        return min;
    }


    bool shifted(const vector<int> &v, int pos1, int pos2) {
        auto size = pos2 - pos1 + 1;
        
        if (size <= 2) {
            return false;
        }

        auto mid = (pos2 + pos1)/2;
        bool leftIncreasing = true;
        bool rightIncreasing = true;
        if (v[mid] - v[pos1] < 0) {
            leftIncreasing = false;
        }
        if (v[pos2] - v[mid] < 0) {
            rightIncreasing = false;
        }
        if (leftIncreasing ^ rightIncreasing) {
            return true;
        }

        return false;
    }
};

// tests begin
TEST(Problem153Test, Test1) {
    Solution s;

    vector<int> v;

    // test building blocks
    v = {1};
    EXPECT_EQ(false, s.shifted(v, 0, v.size() - 1));

    v = {1, 1};
    EXPECT_EQ(false, s.shifted(v, 0, v.size() - 1));

    v = {1, 1, 1};
    EXPECT_EQ(false, s.shifted(v, 0, v.size() - 1));

    v = {1, 1, 1};
    EXPECT_EQ(false, s.shifted(v, 0, v.size() - 1));

    v = {2, 3, 1};
    EXPECT_EQ(true, s.shifted(v, 0, v.size() - 1));

    v = {5, 6, 1, 2};
    EXPECT_EQ(true, s.shifted(v, 0, v.size() - 1));

    // test 
    v = {1};
    EXPECT_EQ(1, s.findMin(v));

    v = {1, 1};
    EXPECT_EQ(1, s.findMin(v));

    v = {1, 1, 1};
    EXPECT_EQ(1, s.findMin(v));

    v = {1, 2, 3, 4, 5};
    EXPECT_EQ(1, s.findMin(v));

    v = {3, 6, 1, 2, 2};
    EXPECT_EQ(1, s.findMin(v));

    v = {3, 6, 9, 1, 2};
    EXPECT_EQ(1, s.findMin(v));

    v = {3, 5, 6, 9, 1, 2};
    EXPECT_EQ(1, s.findMin(v));

    v = {3, 2, 1};
    EXPECT_EQ(1, s.findMin(v));
}

