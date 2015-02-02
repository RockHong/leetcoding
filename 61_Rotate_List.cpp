/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

// Tag: easy

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        int len = 0;
        ListNode *node = head;
        ListNode *tail = NULL;
        while (node != NULL) {
            ++len;
            tail = node;
            node = node->next;
        }

        int shift = (len - (k%len))%len;

        if (shift == 0) {
            return head;
        }

        ListNode *newHead = head;
        ListNode *newTail = NULL;
        for (int i = 0; i < shift; ++i) {
            newTail = newHead;
            newHead = newHead->next;
        }
        newTail->next = NULL;
        tail->next = head;

        return newHead;
    }

};

// tests begin
TEST(Problem61Test, Test1) {
    Solution s;

    // null
    EXPECT_EQ(NULL, s.rotateRight(NULL, 3));

    // [1]
    ListNode n11(11);
    EXPECT_EQ(&n11, s.rotateRight(&n11, 6));

    // [1,2,3], k=2
    ListNode n21(21);
    ListNode n22(22);
    ListNode n23(23);
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n21, s.rotateRight(&n21, 0));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n23, s.rotateRight(&n21, 1));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n22, s.rotateRight(&n21, 2));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n21, s.rotateRight(&n21, 3));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n23, s.rotateRight(&n21, 4));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n22, s.rotateRight(&n21, 5));
    n21.next = &n22;
    n22.next = &n23;
    n23.next = NULL;
    EXPECT_EQ(&n21, s.rotateRight(&n21, 6));

}
