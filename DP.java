
public class DP {

	
	
	/**
	 * 
	 * @param total : total amount to give change
	 * @param c : all denomination
	 * @return
	 */
	private int recIntcoinChangeDup(int total,int c[]) {
		
		if (total <= 0) {		//To handle -ve values
			return 0;
		}else {
			int totalItems = c.length;
			int min1 = 9999;
			for(int i=0;i< totalItems;i++) {
				//Obs : no summation sign like in trees problem
				int res = recIntcoinChangeDup(total - c[i], c) + 1;
				if(res < min1)
					min1 = res;
			}
//			int min = Math.min(recIntcoinChangeDup(total - 1, c), min1);
//			return min;
//			If we use same commented logic for max finding it works fine because we are finding max
//			however,due to min calculation we always gets result 0 because see the base condition.
			return min1;
		}	
	}

	/**
	 * 
	 * @param size : total knapsack size
	 * @param s : all sizess s.t s1<s2<s3
	 * @param v : values corresponding to sizes
	 * @return
	 */
	private int recIntKnapSackDup(int size,int s[],int v[]) {
		
		if (size <= 0) {		//To handle -ve values
			return 0;
		}else {
			int totalItems = s.length;
			int max1 = -999;
			for(int i=0;i< totalItems;i++) {
				int res = recIntKnapSackDup(size - s[i], s, v) + v[i];
				if(res > max1)
					max1= res;
			}
//			int max = Math.max(recIntKnapSackDup(size - 1, s, v), max1);
//			If above line is uncommented,still code works fine to mainaintain symmetry with the above recIntcoinChangeDup
//			I have to made this change
			return max1;
		}
		
	}
	
	public static void main(String[] args) {
		
		DP dp = new DP ();
		int s[] = {5,2,3,1};
		int v[] = {3,80,2,30};
		System.out.println(" The Max Value "+dp.recIntKnapSackDup(10, s, v));
		
		int c[] = {25,50,100};
		System.out.println(" The Max Value " + dp.recIntcoinChangeDup(125,c));
	}

}
