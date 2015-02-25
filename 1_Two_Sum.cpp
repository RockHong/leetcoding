/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// TODO: are there other ways which better than O(nlogn)? are there other ways to do it in-place?
class Solution {
public:
    // use the assumption that "each input would have exactly one solution"
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> cp = numbers;
        // O(nlogn)
        std::sort(cp.begin(), cp.end());

        //find the upper bound, O(logn)
        int bound = findUpperBound(cp, target);

        //find the target, O(n)
        vector<int> result(2);
        findTarget(cp, bound, target, result);

        //find the original index, O(n)
        int size = numbers.size();
        for (int i = 0; i < size; ++i) {
            if (numbers[i] == result[0]) {
                result[0] = i + 1;
                break;
            }
        }

        for (int i = size - 1; i >= 0; --i) {
            if (numbers[i] == result[1]) {
                result[1] = i + 1;
                break;
            }
        }

        if (result[0] > result[1]) {
            std::swap(result[0], result[1]);
        }

        return result;
    }

    int findUpperBound(const vector<int> &vec, int target) {
        int upper = target - vec[0];
        int l = 0;
        int r = vec.size() - 1;
        int m;
        while (l < r) {
            m = (l+r)/2;
            if (vec[m] == upper) {
                return m;
            } else if (vec[m] > upper) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    void findTarget(const vector<int> &cp, int bound, int target, vector<int> &result) {
        int l = 0;
        int r = bound;
        int sum;

        while (l < r) {
            sum = cp[l] + cp[r];
            if (sum == target) {
                result[0] = cp[l];
                result[1] = cp[r];
                return;
            } else if (sum > target) {
                --r;
            } else {
                ++l;
            }
        }
    }

};

// Lesson: come out with tests first, that is test driven
// tests begin
TEST(Problem1Test, Test1) {
    Solution s;

    int target;
    int index1;
    int index2;
    vector<int> result;

    vector<int> v1 = {2,7,11,15};
    target = 9;
    index1 = 1;
    index2 = 2;
    result = s.twoSum(v1, target);
    EXPECT_EQ(index1, result[0]);
    EXPECT_EQ(index2, result[1]);

    vector<int> v2 = {19,-2,1,7,12};
    target = 5;
    index1 = 2;
    index2 = 4;
    result = s.twoSum(v2, target);
    EXPECT_EQ(index1, result[0]);
    EXPECT_EQ(index2, result[1]);

    vector<int> v3 = {1,0,1,0};
    target = 0;
    index1 = 2;
    index2 = 4;
    result = s.twoSum(v3, target);
    EXPECT_EQ(index1, result[0]);
    EXPECT_EQ(index2, result[1]);

    vector<int> v4 = {1,0,1,0,1};
    target = 0;
    index1 = 2;
    index2 = 4;
    result = s.twoSum(v4, target);
    EXPECT_EQ(index1, result[0]);
    EXPECT_EQ(index2, result[1]);

    vector<int> v5 = {-1,-2,-3};
    target = -3;
    index1 = 1;
    index2 = 2;
    result = s.twoSum(v5, target);
    EXPECT_EQ(index1, result[0]);
    EXPECT_EQ(index2, result[1]);

}




