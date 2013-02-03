public class RemoveDuplicate {
 /**
  * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	For example,
	Given input array A = [1,1,2],
	Your function should return length = 2, and A is now [1,2].
  * @param A
  * @return
  */
	public int removeDuplicates(int[] A) {
		// array is sorted so we know the range of array is [x...n]
		int len = A.length;
		if (len > 1) {
			int first = A[0];
			int last = A[len - 1];
			len = Math.abs(last - first) + 1;
			int start = 0;
			int end = 1;
			while (start != len - 1) {
				while (A[start] == A[end]) {
					end++;	//find the range of duplicate <Start ... end>
				}
				for (int i = start + 1, j = end; i < end; i++) {
					A[i] = A[j];  //Replace the content
				}
				start = start + 1;	//increment to next position
			}
		}

		return len;
	}

}
