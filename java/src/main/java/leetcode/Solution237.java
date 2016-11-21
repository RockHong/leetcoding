package leetcode;


/*
 * Write a function to delete a node (except the tail) in a singly linked list, 
 * given only access to that node.
 * 
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
 * the linked list should become 1 -> 2 -> 4 after calling your function.
 */

 
/*
 * the key of this question is how to understand the word "delete", since
 * we have a very limited information (given only access to that node to delete)
 */
public class Solution237 {
    public void deleteNode(ListNode node) {
    	ListNode tail = null;
        while (node.next != null) {
        	node.val = node.next.val;
        	tail = node;
        	node = node.next;
        }
        tail.next = null;
    }
}
