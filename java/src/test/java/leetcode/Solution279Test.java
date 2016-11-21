package leetcode;

import org.junit.Assert;
import org.junit.Test;

import leetcode.Solution279;



public class Solution279Test {

	@Test
	public void case1() {
		Solution279 s = new Solution279();
		Assert.assertEquals(1, s.numSquares(1));
		Assert.assertEquals(1, s.numSquares(4));
		Assert.assertEquals(1, s.numSquares(9));
		Assert.assertEquals(2, s.numSquares(26));
		Assert.assertEquals(2, s.numSquares(10001));
		Assert.assertEquals(1, s.numSquares(10000));
		Assert.assertEquals(3, s.numSquares(12));
		Assert.assertEquals(2, s.numSquares(13));
		Assert.assertEquals(2, s.numSquares(90016));
		//Assert.assertEquals(1, s.numSquares(100000000));
		//Assert.assertEquals(2, s.numSquares(100000001));
	}
}
