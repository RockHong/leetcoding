package leetcode.solved;

import leetcode.ListNode;

// 147. Insertion Sort List
// Sort a linked list using insertion sort.

// PASSED leetcode

public class LinkedList147 {
    public ListNode insertionSortList(ListNode head) {
        // 1 put sorted nodes into a new 'sorted list'
    	// 2 fetch a node from left nodes in the original list, compare it with nodes in the 'sorted list'
    	// 3 find the insertion position, insert it
    	
    	if (head == null || head.next == null) {
    		return head;
    	}
    	
    	ListNode unsorted = head.next;
    	ListNode sorted = head;
    	sorted.next = null;
    	
    	ListNode pu = unsorted;
    	while (pu != null) {
    		ListNode tmp = pu.next;
    		
    		if (pu.val < sorted.val) {
    			pu.next = sorted;
    			sorted = pu;
    		} else {
    			ListNode p1 = sorted;
    			ListNode p2 = sorted.next;
    			while (p2 != null) {
    				if (p2.val > pu.val) {
    					break;
    				}
    				p1 = p2;
    				p2 = p2.next;
    			}
    			if (p2 == null) {
    				// the insertion position is the end of 'sorted'
    				p1.next = pu;
    				pu.next = null;
    			} else {
    				p1.next = pu;
    				pu.next = p2;
    			}
    		}
    		pu = tmp;
    	}
    	
    	return sorted;
    }
}
