/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return isSameTree_recursive(p, q);
    } 

    // way 1, recursive version, use pre-order traversal, so that we can
    // test node equality earlier 
    bool isSameTree_recursive(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree_recursive(p->left, q->left) && isSameTree_recursive(p->right, q->right);
    }

    // TODO: no-recursive version
};

// tests begin
TEST(Problem100Test, Test1) {
    Solution s;

    EXPECT_TRUE(s.isSameTree(NULL, NULL));

    //
    TreeNode p1(1);
    TreeNode q1(1);
    EXPECT_TRUE(s.isSameTree(&p1, &q1));
    q1.val = 2;
    EXPECT_FALSE(s.isSameTree(&p1, &q1));

    //
    TreeNode p21(21);
    TreeNode p22(22);
    TreeNode p23(23);
    p21.left = &p22;
    p21.right = &p23;
    TreeNode q21(21);
    TreeNode q22(22);
    TreeNode q23(23);
    q21.left = &q22;
    q21.right = &q23;
    EXPECT_TRUE(s.isSameTree(&p21, &q21));
    q23.val = 0;
    EXPECT_FALSE(s.isSameTree(&p21, &q21));

    //
    TreeNode p31(31);
    TreeNode p32(32);
    TreeNode q31(31);
    TreeNode q32(32);
    p31.left = &p32;
    q31.right = &q32;
    EXPECT_FALSE(s.isSameTree(&p31, &q31));
}
