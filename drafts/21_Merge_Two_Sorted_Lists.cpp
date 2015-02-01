/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }

        if (l2 == NULL) {
            return l1;
        }

        ListNode headTmp(0);
        ListNode *p0 = &headTmp;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *win = NULL;
        bool decreasing = isDecreasing(l1, l2);
        while (p1 != NULL && p2 != NULL) {
            win = getWinner(&p1, &p2, decreasing);
            p0->next = win;
            p0 = win;
        }

        return p0->next;
    }

    ListNode * getWinner(ListNode **p1, ListNode **p2, bool decreasing) const {
        if (decreasing) {
            if ((*p1)->val > (*p2)->val) {
                *p1 = (*p1)->next;
                return *p1;
            } else {
                *p2 = (*p2)->next;
                return *p2;
            }
        } else {
            if ((*p1)->val < (*p2)->val) {
                *p1 = (*p1)->next;
                return *p1;
            } else {
                *p2 = (*p2)->next;
                return *p2;
            }
        }
    }

    bool isDecreasing(ListNode *l1, ListNode *l2) const {
        int result = isDecreasing(l1);
        if (result == 1) {
            return true;
        }
        if (result == -1) {
            return false;
        }

        result = isDecreasing(l2);
        return result == -1 ? false : true;
    }

    // 1, yes; -1, no; 0, unknown
    int isDecreasing(ListNode *l) const {
        ListNode *p1 = l;
        ListNode *p2 = l->next;

        while(p1 != NULL && p2 != NULL) {
            if (p1->val > p2->val) {
                return 1;
            }
            if (p1->val < p2->val) {
                return -1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return 0;
    }
};

// tests begin
TEST(Problem21Test, Test1) {
    // null, null

    // [1], null

    // [2], [1]

    // [1,2,3], [2,3,4]

    // [3,2,1], [5,3,0]

    // [1,1,1], [2,2]
}
