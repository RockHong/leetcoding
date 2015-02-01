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
}

