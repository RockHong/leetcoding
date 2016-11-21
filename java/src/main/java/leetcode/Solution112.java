package leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
        
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */




//Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution112 {
    public boolean hasPathSum(TreeNode root, int sum) {
    	List<TreeNode> path = findPath(root, sum);
        return  path != null && !path.isEmpty();
    }
    
    public List<TreeNode> findPath(TreeNode root, int sum) {
    	if (root == null) {
    		return null;
    	}
    	
    	Stack<TreeNode> stack = new Stack<TreeNode>();
    	stack.add(root);
    	
    	List<TreeNode> path = new ArrayList<TreeNode>();
    	
    	int n = 0;
    	
    	while(!stack.empty()) {
    		TreeNode node = stack.pop();
    		if (node.right != null) {
    			stack.add(node.right);
    		}
    		if (node.left != null) {
    			stack.add(node.left);
    		}
    		
    		n += node.val;
    		path.add(node);
    		
    		if (isLeaf(node)) {
    			if (n == sum) {
    				return path;
    			} else {
    				if (!stack.empty()) {
        				n = reset(path, stack.peek());	
    				}
    			}
    			
    		}
    		
    	}
    	return null;
    }
    
    private boolean isLeaf(TreeNode node) {
    	return node.left == null && node.right == null;
    }
    
    
    private int reset(List<TreeNode> path, TreeNode node) {
    	int keep = 0;
    	int newSum = 0;
    	for (int i = 0; i < path.size(); ++i) {
    		TreeNode p = path.get(i);
    		newSum += p.val;
            if (isChildOf(p, node)) {
    			keep = i;
    			break;
    		}
    	}
    	
    	int len = path.size();
    	for (int i = len - 1; i > keep; --i) {
    		path.remove(i);
    	}
    	return newSum;
    }
    
    private boolean isChildOf(TreeNode p, TreeNode c) {
    	if (p.left == c) {
    		return true;
    	}
    	if (p.right == c) {
    		return true;
    	}
    	return false;
    }
}