/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *           3
 *          / \
 *         9  20
 *           /  \
 *          15   7
 * return its level order traversal as:
 *     [
 *       [3],
 *       [9,20],
 *       [15,7]
 *     ]
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

// Tag: easy

#include "gtest/gtest.h"
#include <iostream>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        static const TreeNode * LEVEL_MARK = NULL;
        
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<const TreeNode *> q;
        q.push(root);
        q.push(LEVEL_MARK);

        const TreeNode *node = NULL;
        vector<int> level;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node == LEVEL_MARK) {
                level.shrink_to_fit();
                result.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(LEVEL_MARK);
                }
                continue;
            }
            level.push_back(node->val);
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        return result;
    }
};

// tests begin
TEST(Problem102Test, Test1) {
    Solution s;

    TreeNode n11(1);
    TreeNode n12(2);
    TreeNode n13(3);
    TreeNode n14(4);
    TreeNode n15(5);
    n11.left = &n12;
    n11.right = &n13;
    n13.left = &n14;
    n13.right = &n15;
    vector<vector<int>> result = s.levelOrder(&n11);
    EXPECT_EQ(3, result.size());
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(1, result[0][0]);
    EXPECT_EQ(2, result[1].size());
    EXPECT_EQ(2, result[1][0]);
    EXPECT_EQ(3, result[1][1]);
    EXPECT_EQ(2, result[2].size());
    EXPECT_EQ(4, result[2][0]);
    EXPECT_EQ(5, result[2][1]);

}
