/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include "gtest/gtest.h"
#include <vector>
#include <stack>
#include <utility>

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
    vector<int> postorderTraversal(TreeNode *root) {
        // no recursion means using stack...

        // recursion version
        // if (root->left != NULL) postorderTraversal(root->left);
        // if (root->right != NULL) postorderTraversal(root->right);
        // cout << root->val; 

        vector<int> res;

        if (root == NULL) {
            return res;
        }

        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));

        TreeNode * node;
        while(!s.empty()) {
            pair<TreeNode *, bool> &current = s.top(); // top() returns ref
            node = current.first;

            if (current.second) {//visited
                res.push_back(node->val);
                s.pop();
                continue;
            } else {
                current.second = true;
            }

            if (node->right != NULL) {
                s.push(make_pair(node->right, false));
            }
            if (node->left != NULL) {
                s.push(make_pair(node->left, false));
            }
        }
        
        return res;
    }
};

// tests begin
string to_string(const vector<int> &v) {
    ostringstream oss;
    for (auto ele: v) {
        oss << ele <<' ';
    }
    return oss.str();
}

TEST(Problem145Test, Test1) {
    Solution s;

    // null case
    EXPECT_TRUE(s.postorderTraversal(NULL).empty());

    // root only
    TreeNode n11(11);
    EXPECT_EQ("11 ", to_string(s.postorderTraversal(&n11)));

    // left children only
    TreeNode n21(21);
    TreeNode n22(22);
    TreeNode n23(23);
    n21.left = &n22;
    n22.left = &n23;
    EXPECT_EQ("23 22 21 ", to_string(s.postorderTraversal(&n21)));

    // left children only

    // full tree
}
