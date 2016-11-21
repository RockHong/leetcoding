package leetcode;

import org.junit.Assert;
import org.junit.Test;



public class LinkedList234Test {


	@Test
	public void nullTest() {
		LinkedList234 s = new LinkedList234();
		Assert.assertTrue(s.isPalindrome(null));
	}
	
	@Test
	public void singleTest() {
		LinkedList234 s = new LinkedList234();		
		Assert.assertTrue(s.isPalindrome(new ListNode(1)));
	}
	
	@Test
	public void twoNodesTest() {
		LinkedList234 s = new LinkedList234();
		ListNode head = new ListNode(1);
		head.next = new ListNode(1);
		Assert.assertTrue(s.isPalindrome(head));
	}
	
	@Test
	public void twoNodesTest2() {
		LinkedList234 s = new LinkedList234();
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		Assert.assertFalse(s.isPalindrome(head));
	}
	
	@Test
	public void normalTest1() {
		LinkedList234 s = new LinkedList234();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		node1.next = node2;
		node2.next = node3;
		Assert.assertFalse(s.isPalindrome(node1));
	}
	
	@Test
	public void normalTest1_2() {
		LinkedList234 s = new LinkedList234();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(1);
		node1.next = node2;
		node2.next = node3;
		Assert.assertTrue(s.isPalindrome(node1));
	}
	
	@Test
	public void normalTest2() {
		LinkedList234 s = new LinkedList234();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(4);
		ListNode node5 = new ListNode(5);
		ListNode node6 = new ListNode(6);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		node5.next = node6;
		Assert.assertFalse(s.isPalindrome(node1));
	}
	
	@Test
	public void normalTest2_2() {
		LinkedList234 s = new LinkedList234();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(3);
		ListNode node5 = new ListNode(2);
		ListNode node6 = new ListNode(1);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		node5.next = node6;
		Assert.assertTrue(s.isPalindrome(node1));
	}

}
