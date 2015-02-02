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
        // bool decreasing = isDecreasing(l1, l2);
        bool decreasing = false;
        while (p1 != NULL && p2 != NULL) {
            win = getWinner(&p1, &p2, decreasing);
            p0->next = win;
            p0 = win;
        }

        return p0->next;
    }

    ListNode * getWinner(ListNode **p1, ListNode **p2, bool decreasing) const {
        ListNode *win = NULL;
        if (decreasing) {
            if ((*p1)->val > (*p2)->val) {
                win = *p1;
                *p1 = (*p1)->next;
                return win;
            } else {
                win = *p2;
                *p2 = (*p2)->next;
                return win;
            }
        } else {
            if ((*p1)->val < (*p2)->val) {
                win = *p1;
                *p1 = (*p1)->next;
                return win;
            } else {
                win = *p2;
                *p2 = (*p2)->next;
                return win;
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
    Solution s;

    // null, null
    EXPECT_EQ(NULL, s.mergeTwoLists(NULL, NULL))<<"case: null, null";

    // [1], null
    ListNode n11(1);
    EXPECT_EQ(&n11, s.mergeTwoLists(&n11, NULL))<<"case: [1], null";

    // [2], [1]
    ListNode n21(2);
    ListNode n22(1);
    EXPECT_EQ(&n22, s.mergeTwoLists(&n21, &n22))<<"case: [2], [1]";

    // [3,6], [1,9]
    ListNode n31(3);
    ListNode n32(6);
    n31.next = &n32;
    ListNode n33(1);
    ListNode n34(9);
    n33.next = &n34;
    ListNode *head3 = s.mergeTwoLists(&n31, &n33);
    EXPECT_EQ(&n33, head3);
    EXPECT_EQ(1, head3->val);
    head3 = head3->next;
    EXPECT_EQ(3, head3->val);
    head3 = head3->next;
    EXPECT_EQ(6, head3->val);
    head3 = head3->next;
    EXPECT_EQ(9, head3->val);

    // [1,2,3], [2,3,4]

    // [3,2,1], [5,3,0]

    // [1,1,1], [2,2]
}
