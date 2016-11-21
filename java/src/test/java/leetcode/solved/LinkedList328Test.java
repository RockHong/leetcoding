package leetcode.solved;

import org.junit.Test;

import leetcode.ListNode;
import leetcode.solved.LinkedList328;

public class LinkedList328Test {

	@Test
	public void nullTest() {
		LinkedList328 s = new LinkedList328();
		ListNode.print(s.oddEvenList(null));
	}
	
	@Test
	public void singleTest() {
		LinkedList328 s = new LinkedList328();		
		ListNode.print(s.oddEvenList(new ListNode(1)));
	}
	
	@Test
	public void twoNodesTest() {
		LinkedList328 s = new LinkedList328();
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		ListNode.print(s.oddEvenList(head));
	}
	
	@Test
	public void normalTest1() {
		LinkedList328 s = new LinkedList328();
		ListNode node1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		node1.next = node2;
		node2.next = node3;
		ListNode.print(s.oddEvenList(node1));
	}
	
	@Test
	public void normalTest2() {
		LinkedList328 s = new LinkedList328();
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
		ListNode.print(s.oddEvenList(node1));
	}
}
