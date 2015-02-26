/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) {
            return head;
        }

        // Lesson: a common trick for linked list problem
        ListNode *p1 = head;
        for (int i = 1; i < n; ++i) {
            p1 = p1->next;
        }

        ListNode *p2 = head;
        ListNode *prev = NULL;
        while (p1->next != NULL) {
            prev = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (prev == NULL) {
            head = p2->next;
        } else {
            prev->next = p2->next;
        }
        return head;
    }
};

// tests begin
TEST(Problem19Test, Test1) {
    Solution s;
    ListNode *head;

    // null, n=0
    EXPECT_EQ(NULL, s.removeNthFromEnd(NULL, 0));

    // 1, n=1
    ListNode n11(11);
    EXPECT_EQ(NULL, s.removeNthFromEnd(&n11, 1));

    // 1,2,3,4,5; n=1,3,5
    ListNode n21(21);
    ListNode n22(22);
    ListNode n23(23);
    ListNode n24(24);
    ListNode n25(25);
    n21.next = &n22;
    n22.next = &n23;
    n23.next = &n24;
    n24.next = &n25;
    head = s.removeNthFromEnd(&n21, 1);
    EXPECT_EQ(NULL, n24.next);
    n21.next = &n22;
    n22.next = &n23;
    n23.next = &n24;
    n24.next = &n25;
    head = s.removeNthFromEnd(&n21, 5);
    EXPECT_EQ(head, &n22);
    n21.next = &n22;
    n22.next = &n23;
    n23.next = &n24;
    n24.next = &n25;
    head = s.removeNthFromEnd(&n21, 3);
    EXPECT_EQ(n22.next, &n24);
}
