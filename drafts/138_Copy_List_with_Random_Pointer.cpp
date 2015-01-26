/* 
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, int> sourceMap;
        unordered_map<int, RandomListNode *> destMap;

        if (head == NULL) {
            return head;
        }

        int index = 1;
        RandomListNode *headCp = new RandomListNode(head->label);
        sourceMap[head] = index;
        destMap[index] = headCp;
        index++;

        RandomListNode *copied = headCp;
        RandomListNode *node = head->next;
        while (node != NULL) {
            RandomListNode *tmp = new RandomListNode(node->label);
            sourceMap[node] = index;
            destMap[index] = tmp;
            ++index;

            copied->next = tmp;
            copied = tmp;
            node = node->next;
        }

        node = head;
        copied = headCp;
        while (node != NULL) {
            if (node->random != NULL) {
                copied->random = destMap[sourceMap[node->random]];
            }
            node = node->next;
        }
        
        return chead;
    }
};
