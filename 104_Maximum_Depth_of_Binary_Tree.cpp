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
        return maxDepth_recursion(root);
    }

    // way 1, recursion
    // Lesson, when solve a tree problem, think about recursion, since
    // tree is a "recursive" data structure
    // recursively find the max depth of "left part" and "right part"
    int maxDepth_recursion(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int depthL = 1;
        int depthR = 1;
        if (root->left != NULL ) {
            depthL = maxDepth_recursion(root->left) + 1;
        }
        if (root->right != NULL ) {
            depthR = maxDepth_recursion(root->right) + 1;
        }

        return depthL > depthR ? depthL : depthR;
    }

    // TODO: no-recursive version
};

// tests begin
TEST(Problem104Test, Test1) {
    Solution s;

    // null
    EXPECT_EQ(0, s.maxDepth(NULL));

    // 1 node
    TreeNode n11(11);
    EXPECT_EQ(1, s.maxDepth(&n11));

    // 2 nodes
    TreeNode n21(21);
    TreeNode n22(22);
    n21.left = &n22;
    EXPECT_EQ(2, s.maxDepth(&n21));

    // 3 nodes
    TreeNode n31(31);
    TreeNode n32(32);
    TreeNode n33(33);
    n31.left = &n32;
    n31.right = &n33;
    EXPECT_EQ(2, s.maxDepth(&n31));

    // left children only
    TreeNode n41(41);
    TreeNode n42(42);
    TreeNode n43(43);
    n41.left = &n42;
    n42.left = &n43;
    EXPECT_EQ(3, s.maxDepth(&n41));

    // right children only
    TreeNode n51(51);
    TreeNode n52(52);
    TreeNode n53(53);
    n51.right = &n52;
    n52.right = &n53;
    EXPECT_EQ(3, s.maxDepth(&n51));

    // two paths both have the max depth
}
