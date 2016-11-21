package leetcode;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

public class ListNodeTest {

	@Test
	public void makeListTest() {
		ListNode.print(ListNode.makeList(null));
		
		int[] list1 = {1};
		ListNode.print(ListNode.makeList(list1));
		
		int[] list2 = {1,2};
		ListNode.print(ListNode.makeList(list2));
		
		int[] list3 = {1,2,3};
		ListNode.print(ListNode.makeList(list3));
	}
	
	@Test
	public void compareTest() {
		int[] list1 = {1,2,3};
		int[] list2 = {1,2,3};
		
		Assert.assertTrue(ListNode.compare(ListNode.makeList(list1), ListNode.makeList(list2)));
	}
	
	@Test
	public void compareTest2() {
		int[] list1 = {1,1,1};
		int[] list2 = {1,2,3};
		
		Assert.assertFalse(ListNode.compare(ListNode.makeList(list1), ListNode.makeList(list2)));
	}
}
