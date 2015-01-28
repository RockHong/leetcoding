/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
    }

    // way 1, recursion
    int maxDepth_recursion(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int depthL = 0;
        int depthR = 0;
        if (root->left != NULL ) {
            depthL = maxDepth_recursion(root->left) + 1;
        }
        if (root->right != NULL ) {
            depthR = maxDepth_recursion(root->right) + 1;
        }

        return depthL > depthR ? depthL : depthR;
    }
};

// tests begin
    // null
    // 1 node
    // 2 nodes
    // 3 nodes
    // left children only
    // right children only
    // two paths have the max depth
