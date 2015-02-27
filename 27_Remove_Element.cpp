/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

// Tag: easy
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (A == NULL || n == 0) {
            return 0;
        }

        // invariant: those equals with @elem are put into tail
        int left = 0;
        int right = n - 1;
        int size = n;
        while (left < right) {
            if (A[left] != elem) {
                ++left;
            } else {
                while (A[right] == elem && left < right) {
                    --right;
                    --size;
                }
                // swap, less memory, but not faster maybe
                A[left] += A[right];
                A[right] = A[left] - A[right];
                A[left] = A[left] - A[right];

                --size;
                ++left;
                --right;
            }
        }

        if (left == right && A[left] == elem) {
            --size;
        }

        return size;
    }
};

// tests begin
// Lesson: when thinking about the algorithm design, come up with case tests meanwhile
TEST(Problem27Test, Test1) {
    Solution s;

    EXPECT_EQ(0, s.removeElement(NULL, 1, 888));
    
    int a1[] = {1};
    EXPECT_EQ(0, s.removeElement(a1, 0, 888));

    int a2[] = {1};
    EXPECT_EQ(0, s.removeElement(a2, 1, 1));

    int a3[] = {1, 2};
    EXPECT_EQ(1, s.removeElement(a3, 2, 1));
    EXPECT_EQ(2, a3[0]);

    int a4[] = {1, 2};
    EXPECT_EQ(1, s.removeElement(a4, 2, 2));
    EXPECT_EQ(1, a4[0]);

    int a5[] = {1, 1, 2};
    EXPECT_EQ(1, s.removeElement(a5, 3, 1));
    EXPECT_EQ(2, a5[0]);

    int a6[] = {1, 2, 2};
    EXPECT_EQ(1, s.removeElement(a6, 3, 2));
    EXPECT_EQ(1, a6[0]);

    int a7[] = {1, 2, 2, 3};
    EXPECT_EQ(2, s.removeElement(a7, 4, 2));
    EXPECT_EQ(4, a7[0] + a7[1]);

    int a8[] = {1, 2, 3};
    EXPECT_EQ(3, s.removeElement(a8, 3, 999));

    int a9[] = {1, 1, 1};
    EXPECT_EQ(0, s.removeElement(a9, 3, 1));
}
