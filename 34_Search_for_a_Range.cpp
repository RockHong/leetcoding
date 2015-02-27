/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // think about searching 8 in {8,8,8,...} and {8,8,8,...,9,9,9,...}
    // will the algorithm performs good?
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result = {-1, -1};
        if (A == NULL || n == 0) {
            return result;
        }

        double leftMagic = target - 0.5;
        double rightMagic = target + 0.5;
        int leftStop = search(A, n, leftMagic);
        bool found = false;
        if (A[leftStop] == target) {
            result[0] = leftStop;
            found = true;
        } else if (leftStop + 1 < n && A[leftStop+1] == target) {
            result[0] = leftStop + 1;
            found = true;
        }
        if (found) {
            int rightStop = search(A, n, rightMagic);
            if (A[rightStop] == target) {
                result[1] = rightStop;
            } else if (rightStop > 0 && A[rightStop-1] == target) {
                result[1] = rightStop - 1;
            }
        }
        
        return result;
    }

    int search(int A[], int n, double target) {
        int left = 0;
        int right = n - 1;
        int mid;
        while (left < right) {
            mid = (left + right)/2;
            if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

// tests begin
TEST(Problem34Test, Test1) {
    Solution s;
    vector<int> result;

    int a1[] = {5,7,7,8,8,10};
    result = s.searchRange(a1, 6, 8);
    EXPECT_EQ(3, result[0]);
    EXPECT_EQ(4, result[1]);
}
