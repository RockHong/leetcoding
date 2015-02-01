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
    // null
    // [1]
    // [1,2,3], k=2
    // [1,2,3], k=5
}
