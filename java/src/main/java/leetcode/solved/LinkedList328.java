package leetcode.solved;

import leetcode.ListNode;

/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 * 
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * 
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 */

/*
 * two ListNode ref, "odd" and "even"
 * 1) get "next" of these two refs, "oddNext" and "evenNext"
 * 2) update `next` property of "odd" and "even"
 * 
 * PASSED
 */
public class LinkedList328 {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
        	return head;
        }
        
        ListNode odd = head;
        ListNode even = head.next;
        
        ListNode evenHead = even;
        ListNode oddTail = odd;
        
        while (odd != null && even != null) {
        	ListNode oddNext = next(odd);
        	ListNode evenNext = next(even);
        	odd.next = oddNext;
        	even.next = evenNext;
        	oddTail = odd;
        	odd = oddNext;
        	even = evenNext;
        }
        
        if (odd != null) {
        	oddTail = odd;
        }
        
        oddTail.next = evenHead;
        
        return head;
    }
    
    private ListNode next(ListNode node) {
    	if (node.next == null) {
    		return null;
    	}
    	return node.next.next;
    }
}