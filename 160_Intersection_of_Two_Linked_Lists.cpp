/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * For example, the following two linked lists:
 * 
 * A:          a1 -> a2
 *                    \
 *                      c1 -> c2 -> c3
 *                    /            
 * B:  b1 -> b2 -> b3
 * begin to intersect at node c1.
 * 
 * 
 * Notes:
 *   If the two linked lists have no intersection at all, return null.
 *   The linked lists must retain their original structure after the function returns.
 *   You may assume there are no cycles anywhere in the entire linked structure.
 *   Your code should preferably run in O(n) time and use only O(1) memory.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        // consider special intpus...
        if (headA == headB) {
            return headA;
        }

        int lenA = length(headA);
        int lenB =length(headB);
        int diff = lenA - lenB;

        ListNode * startA = NULL;
        ListNode * startB = NULL;
        if (diff < 0) {
            startA = headA;
            startB = ahead(headB, -diff);
        } else if (diff > 0) {
            startA = ahead(headA, diff);
            startB =headB; 
        } else {
            startA = headA;
            startB = headB;
        }

        while(startA != NULL && startB !=NULL && startA != startB) {
            startA = startA->next;
            startB = startB->next;
        }

        if (startA == NULL && startB == NULL) {
            return NULL;
        }
        return startA;
    }

    ListNode * ahead(ListNode *head, int steps) {
        while (steps-- != 0) {
            head = head->next;
        }
        return head;
    }       

    int length(ListNode * head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    // Lesson: if one way is not going to solve the problem, give it up quickly ...
    ListNode * reverse(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode * a = head;
        ListNode * b = a->next;

        //while ( (ListNode *b = a->next) != NULL) {
        //while ( (b = a->next) != NULL) {
        //while ( a->next != NULL) {
        while( a != NULL && b != NULL) {
            // before reverse, store the "old next pointer", otherwise
            // it will lost after calling "b->next = a";
            ListNode *oldNext = b->next;
            b->next = a;

            a = b;
            b = oldNext;
        }

        head->next = NULL;

        return a;
    }
};

// tests begin
TEST(Problem160Test, Test1) {
    Solution s;
    EXPECT_EQ(NULL, s.getIntersectionNode(NULL, NULL));

    // case 2
    /*
     * A:   a1
     *         \
     *           c1 
     *         /            
     * B:   b1
     */
    ListNode c2_a1(1);
    ListNode c2_b1(2);
    ListNode c2_c1(3);
    c2_a1.next = &c2_c1;
    c2_b1.next = &c2_c1;
    EXPECT_EQ(&c2_c1, s.getIntersectionNode(&c2_a1, &c2_b1));
   
    // Lesson: consider special inputs/cases
    // case 2.1, same headers
    EXPECT_EQ(&c2_a1, s.getIntersectionNode(&c2_a1, &c2_a1));

    // case 2.2, headers on same list
    EXPECT_EQ(&c2_c1, s.getIntersectionNode(&c2_a1, &c2_c1));

    // case 3
    /*
     * A:        a1
     *             \
     *              c1 -> c2
     *             /            
     * B:  b1 -> b2
     */
    ListNode c3_a1(1);
    //ListNode c3_a2(2);
    ListNode c3_b1(3);
    ListNode c3_b2(4);
    ListNode c3_c1(5);
    ListNode c3_c2(6);
    //c3_a1.next = &c3_a2;
    c3_a1.next = &c3_c1;
    c3_c1.next = &c3_c2;
    c3_b1.next = &c3_b2;
    c3_b2.next = &c3_c1;
    EXPECT_EQ(&c3_c1, s.getIntersectionNode(&c3_a1, &c3_b1));

    // case 4
    /*
     * A:   a1
     * B:   b1
     */
    ListNode c4_a1(1);
    ListNode c4_b1(2);
    EXPECT_EQ(NULL, s.getIntersectionNode(&c4_a1, &c4_b1));


}
