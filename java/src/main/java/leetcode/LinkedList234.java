package leetcode;

import leetcode.solved.LinkedList206;

//234. Palindrome Linked List

//Given a singly linked list, determine if it is a palindrome.

//Follow up:
//Could you do it in O(n) time and O(1) space?

public class LinkedList234 {
    public boolean isPalindrome(ListNode head) {
    	if (head == null || head.next == null) {
    		return true;
    	}
    	
        // find the "middle point"
    	ListNode rightHalf = middle(head);
    	
    	// reverse the last half
    	ListNode rightHalfReversed = (new LinkedList206()).reverseList(rightHalf);
    	
    	// compare the two halves
    	// size of right half <= size of left half, so use right half to iterate
    	ListNode rightHead = rightHalfReversed;
    	ListNode leftHead = head;
    	while(rightHead != null) {
    		if (rightHead.val != leftHead.val) {
    			return false;
    		}
    		leftHead = leftHead.next;
    		rightHead = rightHead.next;
    	}
    	return true;
    }
    
    // the list must have at lease 2 node
    // 1-2 return 2
    // 1-2-3 return 3
    // 1-2-3-4 return 3
    ListNode middle(ListNode head) {
    	ListNode oneStep = head;
    	ListNode twoStep = head;
    	
    	while(twoStep != null) {
    		oneStep = oneStep.next;
    		twoStep = twoStep.next;
    		if (twoStep != null) {
    			twoStep = twoStep.next;
    		}
    	}
    	
    	return oneStep;
    }
}
