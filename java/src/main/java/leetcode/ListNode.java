package leetcode;

//Definition for singly-linked list.

public class ListNode {
  public int val;
  public ListNode next;
  public ListNode(int x) { val = x; }
  
  public static void print(ListNode head) {
		System.out.print("List: ");
		while(head != null) {
			System.out.print(head.val);
			head = head.next;
		}
		System.out.println();
	}
  
  public static ListNode makeList(int[] input) {
	  if (input == null || input.length == 0) {
		  return null;
	  }
	  
	  ListNode head = new ListNode(input[0]);
	  ListNode p = head;
	  for (int i = 1; i < input.length; ++i) {
		  ListNode node = new ListNode(input[i]);
		  p.next = node;
		  p = node;
	  }
	  p.next = null;
	  
	  return head;
  }
  
  public static boolean compare(ListNode head1, ListNode head2) {
	  if (head1 == head2) {
		  return true;
	  }
	  
	  if (head1 == null || head2 == null) {
		  return false;
	  }
	  
	  ListNode p1 = head1;
	  ListNode p2 = head2;
	  while (p1 != null && p2 != null) {
		  if (p1.val != p2.val) {
			  return false;
		  }
		  p1 = p1.next;
		  p2 = p2.next;
	  }
	  
	  return true;
  }
}
