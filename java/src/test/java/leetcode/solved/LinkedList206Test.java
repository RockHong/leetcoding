package leetcode.solved;

import org.junit.Test;

import leetcode.ListNode;
import leetcode.solved.LinkedList206;

public class LinkedList206Test {

	@Test
	public void nullTest_c() {
		LinkedList206 s = new LinkedList206();
		ListNode.print(s.reverseList_r(null));
	}
	
	@Test
	public void singleTest_c() {
		LinkedList206 s = new LinkedList206();
		ListNode.print(s.reverseList_r(new ListNode(1)));
	}
	
	@Test
	public void twoNodesTest_c() {
		LinkedList206 s = new LinkedList206();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		node1.next = node2;
		ListNode.print(s.reverseList_r(node1));
	}
	
	@Test
	public void normalTest_c() {
		LinkedList206 s = new LinkedList206();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(4);
		ListNode node5 = new ListNode(5);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		ListNode.print(s.reverseList_r(node1));
	}
	
	// use iteration
	@Test
	public void nullTest_i() {
		LinkedList206 s = new LinkedList206();
		ListNode.print(s.reverseList_i(null));
	}
	
	@Test
	public void singleTest_i() {
		LinkedList206 s = new LinkedList206();
		ListNode.print(s.reverseList_i(new ListNode(1)));
	}
	
	@Test
	public void twoNodesTest_i() {
		LinkedList206 s = new LinkedList206();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		node1.next = node2;
		ListNode.print(s.reverseList_i(node1));
	}
	
	@Test
	public void normalTest_i() {
		LinkedList206 s = new LinkedList206();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(4);
		ListNode node5 = new ListNode(5);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		ListNode.print(s.reverseList_i(node1));
	}
}
