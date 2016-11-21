package leetcode;

import java.util.List;

import org.junit.Assert;
import org.junit.Test;

import leetcode.Solution112;
import leetcode.TreeNode;

public class Solution112Test {

	@Test
	public void case1() {
		TreeNode node5 = new TreeNode(5);
		TreeNode node4 = new TreeNode(4);
		TreeNode node11 = new TreeNode(11);
		TreeNode node7= new TreeNode(7);
		TreeNode node2 = new TreeNode(2);
		TreeNode node8 = new TreeNode(8);
		TreeNode node13 = new TreeNode(13);
		
		node5.left = node4;
		node5.right = node8;
		
		node4.left = node11;
		
		node11.left = node7;
		node11.right = node2;
		
		node8.left = node13;
		
		List<TreeNode> path = (new Solution112()).findPath(node5, 22);
		for(TreeNode n: path) {
			System.out.print(n.val);
			System.out.print(" -> ");
		}
		System.out.println(".");
		
	}
	
	@Test
	public void case2() {
		TreeNode node5 = new TreeNode(5);
		TreeNode node15 = new TreeNode(15);
		TreeNode node11 = new TreeNode(11);
		TreeNode node7= new TreeNode(7);
		TreeNode node2 = new TreeNode(2);
		TreeNode node8 = new TreeNode(8);
		TreeNode node13 = new TreeNode(13);
		
		node5.left = node15;
		node5.right = node8;
		
		node15.left = node11;
		node15.right = node2;
		
		node11.left = node7;	
		
		node8.left = node13;
		
		List<TreeNode> path = (new Solution112()).findPath(node5, 22);
		for(TreeNode n: path) {
			System.out.print(n.val);
			System.out.print(" -> ");
		}
		System.out.println(".");
		
	}	
	
	@Test
	public void case3() {
		TreeNode node5 = new TreeNode(5);
		
		Assert.assertFalse((new Solution112()).hasPathSum(node5, 22));
	}
	
	@Test
	public void case5() {
		TreeNode node5 = new TreeNode(5);
		
		Assert.assertTrue((new Solution112()).hasPathSum(node5, 5));
	}
	
	@Test
	public void case6() {
		//TreeNode node5 = new TreeNode(5);
		
		Assert.assertFalse((new Solution112()).hasPathSum(null, 5));
	}
}
