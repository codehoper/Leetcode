import java.util.*;

public class TwoSum {
	
	//TODO : solve with subset sum
	
	/**
	 *  With using sort indices changes so make sure don't change indices
	 * @param sample
	 * @param target
	 * @return
	 */
	private int[] getTwoSum(int sample[],int target) {
		/**
		 * cannot use List<int> why ?
		 * Complexity = O(nlogn)
		 */
		
		Arrays.sort(sample);
		int low = 0;
		int high = sample.length -1;
		int sum = 0;
		int [] indexList = new int[2];
		while(low <= high) {
			sum = sample[low] + sample[high];
			if(sum == target) {
				indexList[0] = low;
				indexList[1] = high;
				break;
			}else if(sum < target) {
				low ++;
			}else {
				high --;
			}
		}
		return indexList;
	}
	
	public static void main(String args[]) {
		TwoSum twosum = new TwoSum();
		int [] sample = {150,24,79,50,88,345,3};
		int target = 200;
		int [] test = twosum.getTwoSum(sample, target);
		for (int i=0;i<test.length;i++) {
			System.out.print(test[i] + " ");
		}
	}

	
}
