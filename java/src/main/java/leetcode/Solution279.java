package leetcode;

import java.util.Arrays;

/*
 * 279. Perfect Squares
 * 
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 *
 */

public class Solution279 {
    public int numSquares(int n) {
    	int table[] = new int[n + 1]; 
    	Arrays.fill(table, Integer.MAX_VALUE);
        
    	for (int i = 1; i*i <= n;  ++i) {
    		table[i*i] = 1;
    	}
    	
    	for (int i = 1; i <= n; ++i ) {
    		for (int j = 1; i + j*j <=n; ++j) {
    			table[i + j*j] = Math.min(table[i] + 1, table[i + j*j]);
    		}
    	}
    	return table[n];
    }
}
