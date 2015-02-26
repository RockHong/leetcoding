/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * 
 *     For example, given array S = {-1 0 1 2 -1 -4},
 * 
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    // loop1&2 will run O(n^2) steps, and consider the binary search, this implementation will
    // run O(n^2logn)
    // TODO: are there better way?
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if (num.size() < 3) {
            return result;
        }

        std::sort(num.begin(), num.end()); // O(nlogn)

        if (num.front() > 0 || num.back() < 0) {
            return result;
        }
        
        auto third = num.end();
        --third;
        while (*third >= 0) { // loop 1
            auto first = num.begin();
            while (first != third) { // loop 2
                if (*first > 0) {
                    break;
                }
                int secondVal = -(*first + *third);
                if (secondVal < *first || secondVal > *third) {
                    ++first;
                    continue;
                }
                auto firstCopy = first++;
                if (std::binary_search(first, third, secondVal)) { // binary search
                    //cout <<&(*firstCopy) <<" " <<&(*third) <<endl;
                    result.push_back({*firstCopy, secondVal, *third});
                    // go next, skip duplicated "first"
                    while (*first == *firstCopy && first != third) {
                        ++first;
                    }
                }
            }
            // go next, skip duplicated "third"
            int thirdVal = *third;
            --third;
            while (*third == thirdVal && *third >= 0 && third != num.begin() ) {
                --third;
            }
            if (third == num.begin()) {
                break;
            }
        }
        return result;
    }
};

void printResult(vector<vector<int>> result) {
    cout <<"*** printResult begins ***" <<endl;
    for (auto ele: result) {
        cout <<ele[0] <<" " <<ele[1] <<" " <<ele[2] <<endl;
    }
    cout <<"*** printResult ends ***" <<endl;
}

// tests begin
TEST(Problem15Test, Test1) {
    Solution s;
    vector<vector<int>> result;

    // {-1 0 1 2 -1 -4} (-1 0 1) (-1 -1 2)
    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    result = s.threeSum(v1);
    EXPECT_EQ(2, result.size());
    printResult(result);

    // {}
    // {1}
    // {1 2 3}
    // {-1 -2 -3}
    // {0 0 1 2 3}
    // {0 0 0 1}
    // {-1 0 0 0 2}

    // Lesson: input has duplicated elements, like {-1 0 1 1}, the result should contain only one {-1 0 1}
    vector<int> v2 = {-1, 0, 1, 1};
    result = s.threeSum(v2);
    EXPECT_EQ(1, result.size());
    printResult(result);

    vector<int> v3 = {-1, -1, 0, 1, 1};
    result = s.threeSum(v3);
    EXPECT_EQ(1, result.size());
    printResult(result);

    // Lesson: never forget this "simple special" case
    vector<int> v4 = {0, 0, 0};
    result = s.threeSum(v4);
    EXPECT_EQ(1, result.size());
    printResult(result);
}

