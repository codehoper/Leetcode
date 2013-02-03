package com.ub.interview;

public class MaxSubArray {
	/**
	 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
	   For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
	   the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
	 * @param A
	 * @return
	 */
	   public int MaxSubArray(int[] A) {
	        // Start typing your Java solution below
	        // DO NOT write main() function
	        
	        int len = A.length;
	        int sum = 0;
	        int maxSum = -999;
	        int min = -999;
	        for(int i=0;i<len;i++) {
	            sum += A[i];
	            if(sum < 0) {
	                sum = 0;
	                
	            }
	            if(maxSum < sum) {
	                maxSum = sum;
	            }
	            /**
	             * For corner cases [-1,0] [-1,-2,-3]
	             */
	             if(min < A[i])
	                min = A[i];
	        }
	        if(len >= 1 && maxSum == 0) {
	            maxSum = min;
	        }
	        
	        return maxSum;
	    }

	public static void main(String args[]) {
		MaxSubArray max= new MaxSubArray();
		int sample[] = {-1,0};
		System.out.println ("max = "+max.MaxSubArray(sample));
	}
	 
}
