/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree is symmetric:
 * 
 *         1
 *        / \
 *       2   2
 *      / \ / \
 *     3  4 4  3
 * But the following is not:
 *       1
 *      / \
 *     2   2
 *      \   \
 *      3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

// Tag: easy

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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric_recursive(root);
    }

    // way1, recursive version
    bool isSymmetric_recursive(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        return compareChildren(root->left, root->right);
    }

    bool compareChildren(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        }

        if ((left == NULL && right != NULL) 
            || (left != NULL && right == NULL)
            || (left->val != right->val)) {
            return false;
        }

        if (!compareChildren(left->left, right->right)) {
            return false;
        }

        return compareChildren(left->right, right->left);
    }
};

// tests begin
TEST(Problem101Test, Test1) {
    Solution s;

    // null
    EXPECT_TRUE(s.isSymmetric(NULL));

    //
    TreeNode n11(11);
    EXPECT_TRUE(s.isSymmetric(&n11));

    //
    TreeNode n21(21);
    TreeNode n22(22);
    TreeNode n23(23);
    n21.left = &n22;
    n21.right = &n23;
    EXPECT_FALSE(s.isSymmetric(&n21));
    n23.val = 22;
    EXPECT_TRUE(s.isSymmetric(&n21));
    TreeNode n24(24);
    n23.left = &n24;
    EXPECT_FALSE(s.isSymmetric(&n21));

    //
    TreeNode n31(1);
    TreeNode n32(2);
    TreeNode n33(2);
    TreeNode n34(3);
    TreeNode n35(4);
    TreeNode n36(4);
    TreeNode n37(3);
    n31.left = &n32;
    n31.right = &n33;
    n32.left = &n34;
    n32.right = &n35;
    n33.left = &n36;
    n33.right = &n37;
    EXPECT_TRUE(s.isSymmetric(&n31));
    n36.val = 9;
    EXPECT_FALSE(s.isSymmetric(&n31));

}

