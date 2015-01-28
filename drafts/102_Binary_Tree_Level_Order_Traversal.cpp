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
    vector<vector<int> > levelOrder(TreeNode *root) {
    }
};

// tests begin
