/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 -> 2
 * [1,3,5,6], 2 -> 1
 * [1,3,5,6], 7 -> 4
 * [1,3,5,6], 0 -> 0
 */

// Tag: easy

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (A == NULL || n == 0) {
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int mid;
        while (left < right) {
            mid = (left + right)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (A[left] < target) {
            return left + 1;
        } else { // for < and == 
            return left;
        }
    }
};

// tests begin
TEST(Problem35Test, Test1) {
    Solution s;

    int a1[] = {1,3,5,6};
    EXPECT_EQ(2, s.searchInsert(a1, 4, 5));
    EXPECT_EQ(1, s.searchInsert(a1, 4, 2));
    EXPECT_EQ(4, s.searchInsert(a1, 4, 7));
    EXPECT_EQ(0, s.searchInsert(a1, 4, 0));

    EXPECT_EQ(0, s.searchInsert(NULL, 0, 999));

    int a2[] = {1};
    EXPECT_EQ(0, s.searchInsert(a2, 1, 1));
    EXPECT_EQ(1, s.searchInsert(a2, 1, 2));
    EXPECT_EQ(0, s.searchInsert(a2, 1, -1));

    int a3[] = {1,3,5};
    EXPECT_EQ(0, s.searchInsert(a3, 3, 1));
    EXPECT_EQ(1, s.searchInsert(a3, 3, 3));
    EXPECT_EQ(1, s.searchInsert(a3, 3, 2));
    EXPECT_EQ(3 ,s.searchInsert(a3, 3, 6));
    EXPECT_EQ(0, s.searchInsert(a3, 3, -1));
}
