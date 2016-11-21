package leetcode.solved;

import leetcode.ListNode;

// 206. Reverse Linked List

//Reverse a singly linked list.

//Hint:
//A linked list can be reversed either iteratively or recursively. Could you implement both?

// tips: 1) drawing in the white paper helps
// 2) do not consider it too complex, most of times the solution is simple, like this iteration solution of this question

// PASSED leetcode
		
public class LinkedList206 {
    public ListNode reverseList(ListNode head) {
        return reverseList_i(head);
    }
    
    // 1-2-3-4-5
    // | |
    // a b
    public ListNode reverseList_i(ListNode head) {
        if (head == null || head.next == null) {
        	return head;
        }
        
        ListNode pa = head;
        ListNode pb = head.next;
        
        while(pb != null) {
        	ListNode pbnext = pb.next;
        	pb.next = pa;
        	pa = pb;
        	pb = pbnext;
        }
        
        // remember to close the tail
        head.next = null;
        
        // pa is the new head
        return pa;
    }
    
    public ListNode reverseList_r(ListNode head) {
    	if (head == null) {
        	return head;
        }
    	
    	ListNode newHead = reverseList_r_internal(head);
    	head.next = null;
    	return newHead;
    }
    
    public ListNode reverseList_r_internal(ListNode head) {
        if (head.next != null) {
        	ListNode newHead = reverseList_r_internal(head.next);
        	// now head.next becomes tail of sub-list, connect the tail to 'head'
        	head.next.next = head;
        	return newHead;
        } else {
        	return head;
        }
    }
}
