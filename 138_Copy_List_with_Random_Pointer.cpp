/* 
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include "gtest/gtest.h"
#include <iostream>
#include <unordered_map>
#include <string>

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

        // printMap(sourceMap);
        // printMap(destMap);

        node = head;
        copied = headCp;
        while (node != NULL) {
            if (node->random != NULL) {
                copied->random = destMap[sourceMap[node->random]];
            }
            node = node->next;
            copied = copied->next;
        }
        
        return headCp;
    }

    template<typename K, typename T>
    void printMap(const unordered_map<K, T> &map) {
        cout <<"--- printMap begins ---" <<endl;
        for (const auto kv: map) {
            cout<<"key, " <<kv.first <<"; value, " <<kv.second <<endl;
        }
        cout <<"--- printMap ends ---" <<endl;
    }
};

// tests begin

// on cygwin, g++ 4.8.3 has some bug on std::to_string(), so
// provide a simple replacer
string to_string(long long n) {
    ostringstream converter;
    converter << n;
    return converter.str();
}

bool verify(RandomListNode *orig, RandomListNode *cp) {
    RandomListNode * node = orig;
    RandomListNode * node2 = cp;

    if (node == NULL) {
        return node2 == NULL;
    }

    bool same = true;
    cout <<"--- verify begins ---" <<endl;
    while (node != NULL) {
        cout <<"labels, " <<node->label <<", " <<node2->label <<endl;
        cout <<"randoms, " <<(node->random == NULL ? "NULL" : to_string(node->random->label))
            <<", " <<(node2->random == NULL ? "NULL" : to_string(node2->random->label)) <<endl;
        if (node2 == NULL || node->label != node2->label) {
            same = false;
            break;
        }

        if (node->random == NULL && node2->random != NULL) {
            same = false;
            break;
        } else if (node->random != NULL 
                && (node2->random == NULL || node->random->label != node2->random->label)) {
            same = false;
            break;
        }

        node = node->next;
        node2 = node2->next;
    }

    cout <<"--- verify ends ---" <<endl;
    return same;
}

TEST(Problem138Test, Test1) {
    Solution s;
    RandomListNode *cp = NULL;
    
    RandomListNode n11(11);
    RandomListNode n12(12);
    RandomListNode n13(13);
    n11.next = &n12;
    n12.next = &n13;

    EXPECT_TRUE(verify(&n11, &n11));
    cp = s.copyRandomList(&n11);
    EXPECT_TRUE(verify(&n11, cp));

    RandomListNode n21(21);
    RandomListNode n22(22);
    RandomListNode n23(23);
    n21.next = &n22;
    n22.next = &n23;
    n21.random = &n23;
    n22.random = &n23;
    n23.random = &n23;
    cp = s.copyRandomList(&n21);
    EXPECT_TRUE(verify(&n21, cp));
}
