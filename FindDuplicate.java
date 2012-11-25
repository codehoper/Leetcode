public class FindDulplicate {
	
	private void useIndexContentApproach(int sample[]) {
		/**
		 * Make use of sample(content) => make this negative and check this not content  
		 * content = sample[index]
		 * Time : O(n)
		 * space :O(1)
		 */
		int len = sample.length;
		System.out.println("\n repeating element :");
		for (int i=0;i<len;i++) {
			if(sample[Math.abs(sample[i])] > 0) {
				sample[Math.abs(sample[i])] = -sample[Math.abs(sample[i])];
			} else {
				System.out.print(-sample[Math.abs(sample[i])] + " ");
			}
		}
	}
	private void useCountApproach (int sample[]) {
		/**
		 * Space : O(n)
		 * Time :  O(n) 
		 */
		System.out.println("\nRepeating elements");
		int len = sample.length;
		int count[] = new int[len + 1];
		
		for (int i=0;i<len;i++) {
			count[sample[i]] += 1; 
		}
		for (int i=0;i<len;i++) {
			if (count[i] > 1) {
				System.out.print( i +" ");
			}
		}
		
		
	}
	private void useNaiveApproach(int sample[]) {
		/**
		 * RunTime = O(n^2)
		 * Space = O(1)
		 */
		int len = sample.length;
		System.out.println("\nRepeating elements");
		for (int i=0;i<len;i++) {
			int key = sample[i];
			for (int j= i+1;j<len;j++) {
				if(key == sample[j]) {
					System.out.print(key+" ");
				}
			}
		}
	}
	
	public static void main(String args[]) {
		/**
		 * Find repeating number in an array from 1(min) to n(max) 
		 */
		int sample [] = {4, 2, 4, 5, 2, 3, 1};
		FindDulplicate fduplicate = new FindDulplicate();
		fduplicate.useNaiveApproach(sample);
		fduplicate.useCountApproach(sample);
		fduplicate.useIndexContentApproach(sample);
	}
	
	

}
