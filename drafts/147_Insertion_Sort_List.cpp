/*
 * Sort a linked list using insertion sort.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode * sorted = head;
        ListNode * unsorted = sorted->next;
        ListNode * pos;
        ListNode * posPrev;
        ListNode * tmp;
        while (unsorted != NULL) {
            if (unsorted->val >= sorted->val) {
                sorted = unsorted;
                unsorted = unsorted->next;
                continue;
            }
            // find the insertion pos
            pos = head;
            posPrev = NULL;
            while (pos->val < unsorted->val) {
                posPrev = pos;
                pos = pos->next;
            }
            // insert
            if (posPrev == NULL) {
                head = unsorted;
            } else {
                posPrev->next = unsorted;
            }
            tmp = unsorted->next;
            unsorted->next = pos;
            sorted->next = tmp;
            unsorted = tmp;
        }
        return head;
    }
};

// tests begin
// null
// 1
// 1, 1, 1
// 1, 2, 3
// 3, 2, 1, 0
// 1, 3, 2, 6, 5
// 1, 3, 2, 3, 2, 0
