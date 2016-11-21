package leetcode.solved;

import org.junit.Test;

import leetcode.ListNode;
import leetcode.solved.LinkedList147;

public class LinkedList147Test {

	// test null
	// test 1 node list
	// insertion position is the head of sorted list
	// insertion position is the end of sorted list
	// 1-2
	// 2-1
	// 1-2-3
	// 3-2-1
	@Test
	public void test1() {
		int[] list = {3,2,1};
		ListNode head = ListNode.makeList(list);
		ListNode.print((new LinkedList147()).insertionSortList(head));
	}
	// 1-4-2-3
	// 1-3-2-5-4-7-8-9
}
