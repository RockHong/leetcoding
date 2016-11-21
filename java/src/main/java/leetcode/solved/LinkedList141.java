package leetcode.solved;

import leetcode.ListNode;

//141. Linked List Cycle
//Given a linked list, determine if it has a cycle in it.

//Follow up:
//Can you solve it without using extra space?

// PASSED leetcode
public class LinkedList141 {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
        	return false;
        }

        ListNode s1 = head;
        ListNode s2 = forward(s1, 2);
        
        while(s2 != null) {
        	if (s1 == s2) {
        		return true;
        	}
        	s1 = forward(s1, 1);
        	s2 = forward(s2, 2);
        }
        
        return false;
    }
    
    // 'node' is not null
    ListNode forward(ListNode node, int steps) {
    	for (int i = 0; i < steps; ++i) {
    		node = node.next;
    		if (node == null) {
    			return null;
    		}
    	}
    	return node;
    }
}
