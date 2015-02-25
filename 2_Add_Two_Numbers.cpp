/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = NULL;
        ListNode *p = NULL;
        int sum = 0;
        int remainder = 0;
        int carry = 0;
        int val1 = 0;
        int val2 = 0;
        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                val1 = 0;
            } else {
                val1 = p1->val;
                p1 = p1->next;
            }
            if (p2 == NULL) {
                val2 = 0;
            } else {
                val2 = p2->val;
                p2 = p2->next;
            }

            sum = val1 + val2 + carry;
            remainder = sum;
            carry = 0;
            if (sum >= 10) {
                remainder = sum % 10;
                carry = 1;
            }
            ListNode *tmp = new ListNode(remainder);
            if (head == NULL) {
                head = tmp;
                p = head;
            } else {
                p->next = tmp;
                p = tmp;
            }
        }

        if (carry == 1) {
            ListNode *tmp = new ListNode(carry);
            p->next = tmp;
        }

        return head;
    }
};

void printList(ListNode *node) {
    ListNode *p = node;
    while (p != NULL) {
        cout << p->val <<" ";
        p = p->next;
    }
}

// tests begin
TEST(Problem2Test, Test1) {
    Solution s;
    ListNode *result = NULL;

    // (2,4,3) + (5,6,4)
    ListNode l111(2);
    ListNode l112(4);
    ListNode l113(3);
    l111.next = &l112;
    l112.next = &l113;
    ListNode r111(5);
    ListNode r112(6);
    ListNode r113(4);
    r111.next = &r112;
    r112.next = &r113;
    result = s.addTwoNumbers(&l111, &r111);
    EXPECT_EQ(7, result->val);
    EXPECT_EQ(0, result->next->val);
    EXPECT_EQ(8, result->next->next->val);

    // (2,4,3,3) + (5,6,4) and swap operands
    // null + (1) and swap operands
    // (1,2,3) + (1,2,7,9) and swap operands
    // Lesson: (5) + (5), small case with exact testing point

}
