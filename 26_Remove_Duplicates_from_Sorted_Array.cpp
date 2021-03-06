/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array A = [1,1,2],
 * 
 * Your function should return length = 2, and A is now [1,2].
 */

// Tag:

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return removeDuplicates_2(A, n);
    }

    int removeDuplicates_2(int A[], int n) {
        if (A == NULL) {
            return 0;
        }

        int curVal = A[0];
        int nextDiffIndex;
        int newArrayIndex = 1;
        int newSize = n;
        int i = 0;
        // Lesson: think about the invariant of the loop before implement
        while (i < n) {
            nextDiffIndex = findNextDiff(A, n, curVal, i);
            if (nextDiffIndex < n) {
                curVal = A[nextDiffIndex];
            }
            if (nextDiffIndex > i && nextDiffIndex < n) {
                A[newArrayIndex] = A[nextDiffIndex];
            }
            if (nextDiffIndex - i > 1) {
                newSize = newSize - (nextDiffIndex - i - 1);
            }
            newArrayIndex++;
            i = nextDiffIndex;
        }
        return newSize;
    }

    int findNextDiff(int A[], int n, int curVal, int pos) {
        while (A[pos] == curVal && pos < n) {
            ++pos;
        }
        return pos;
    }

    // a little slow
    // Lesson: when design an algorithm, think about worst case
    // for below implementation, 1,1,2,2,3,3,... is the worst case, it runs O(n^2)
    int removeDuplicates_1(int A[], int n) {
        if (A == NULL) {
            return 0;
        }

        int target = A[0];
        for (int i = 1; i < n; ++i) {
            int next = skipDuplicates(A, n, target, i);
            target = A[next];
            shift(A, n, next, next - i);
            n = n - (next - i);
        }
        return n;
    }

    int skipDuplicates(int A[], int n, int target, int start) {
        while (start < n && A[start] == target) {
            ++start;
        }
        return start;
    }

    void shift(int A[], int n, int start, int dist) {
        if (start == n) {
            return;
        }
        for (int i = start; i < n; ++i) {
            A[i - dist] = A[i];
        }
    }

    void printArray(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            cout <<A[i] <<" ";
        }
        cout <<endl;
    }
};

// tests begin
TEST(Problem26Test, Test1) {
    Solution s;
    int len = 0;

    int a1[] = {1};
    len = s.removeDuplicates(a1, 1);
    EXPECT_EQ(1, len);

    int a2[] = {1,1,1};
    len = s.removeDuplicates(a2, 3);
    EXPECT_EQ(1, len);

    int a3[] = {1,1,2,3,3,5};
    len = s.removeDuplicates(a3, 6);
    EXPECT_EQ(4, len);

    int a4[] = {1,2,3,4,5,6};
    len = s.removeDuplicates(a4, 6);
    EXPECT_EQ(6, len);
}


