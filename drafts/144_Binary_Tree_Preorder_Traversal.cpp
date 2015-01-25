/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *     1
 *      \
 *       2
 *      /
 *     3
 * return [1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include "gtest/gtest.h"
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        // function invocation is something like stack, "last invocation,
        // first execution". so use stack with iteration to replace
        // recursion

        // recursion version
        // cout << root->val;
        // if (root->left != NULL) preorderTraversal(root->left);
        // if (root->right != NULL) preorderTraversal(root->right);

        vector<int> res;
        stack<TreeNode *> s;

        if (root == NULL) {
            return res;
        }

        s.push(root);
        TreeNode * node;
        while(!s.empty()) {
            node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right != NULL) {
                s.push(node->right);
            }
            // in recursion version, left is "firstly" processed, so
            // here we put it into stack "lastly"
            if (node->left != NULL) {
                s.push(node->left);
            }
        }

        return res;
    }
};
