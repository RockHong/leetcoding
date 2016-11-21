package leetcode;

/*
 * 404. Sum of Left Leaves
 * 
 * Find the sum of all left leaves in a given binary tree.
 * 
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *   
 *   There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 * 
 */

public class Solution404 {
	
}


//Definition for a binary tree node.
/*class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
 
public class Solution404 {
	int sum = 0;
	
    public int sumOfLeftLeaves(TreeNode root) {
    	return sumOfLeftLeaves_r(root);
    }
	
    // recursion
    public int sumOfLeftLeaves_r(TreeNode root) {
        if (root == null) {
        	return 0;
        }
        
        if (root.left != null) {
        	if (isLeaf(root.left)) {
        		sum += root.left.val;
        	} else {
        		sumOfLeftLeaves_r(root.left);
        	}
        }
        if (root.right != null) {
        	sumOfLeftLeaves_r(root.right);
        }
        return sum;
    }
    
    private boolean isLeaf(TreeNode node) {
    	if (node.left == null && node.right == null) {
    		return true;
    	}
    	return false;
    }
    
    // 
    public int sumOfLeftLeaves_d(TreeNode root) {
    	
    }
    
    //
    public int sumOfLeftLeaves_w(TreeNode root) {
    	if (root == null) {
    		return 0;
    	}
    	
    	Stack<Integer> s = new Stack<>();
    }
}*/