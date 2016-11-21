package leetcode.solved;
//160. Intersection of Two Linked Lists

import leetcode.ListNode;

//Write a program to find the node at which the intersection of two singly linked lists begins.


//For example, the following two linked lists:

//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//begin to intersect at node c1.


//Notes:

//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

// PASSED on leetcode

public class LinkedList160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // 1 find size of two lists
    	// 2 the the diff of two sizes
    	// 3 forward 'diff' steps in the longer list first, then forward in both of lists, compare each nodes
    	
    	if (headA == null || headB == null) {
    		return null;
    	}
    	
    	int sizea = size(headA);
    	int sizeb = size(headB);
    	
    	ListNode pa = headA;
    	ListNode pb = headB;
    	
    	if (sizea > sizeb) {
    		pa = forward(headA, sizea - sizeb);
    	} else {
    		pb = forward(headB, sizeb - sizea);
    	}
    	
    	while (pa != null) {
    		if (pa == pb) {
    			return pa;
    		}
    		pa = pa.next;
    		pb = pb.next;
    	}
    	return null;
    }
    
    ListNode forward(ListNode head, int n) {
    	ListNode node = head;
    	for (int i = 0; i < n; ++i) {
    		node = node.next;
    	}
    	return node;
    }
    
    int size(ListNode head) {
    	int s = 0;
    	while(head != null) {
    		++s;
    		head = head.next;
    	}
    	return s;
    }
}
