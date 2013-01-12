

/**
 * TopDown recursive solution for LCS 
 * 
 * @author hduser
 *
 */
public class LCS {

  /**
	 * 
	 * @param s1
	 * @param s2
	 * @return
	 */
	private int naiveLCS(String s1,String s2) {
		
		int len1 = s1.length();
		int len2 = s2.length();
//		System.out.println("s1 : " + s1 + " s2 : " + s2);
//		int cnt = 1;
		if (len1 <= 0 || len2 <= 0) {
			return 0;
		}
		//
		else if(s1.charAt(len1 - 1) == s2.charAt(len2 - 1)) {
			return 1 + naiveLCS(s1.substring(0, len1 - 1), s2.substring(0,len2 - 1));
//			cnt = ( 1 + naiveLCS(s1.substring(0, len1 ), s2.substring(0,len2 )) );
		}else {
			return Math.max(naiveLCS(s1.substring(0, len1), s2.substring(0,len2 -1)), 
					naiveLCS(s1.substring(0, len1 - 1), s2.substring(0,len2)));
//			cnt = Math.max(naiveLCS(s1.substring(0, len1 + 1), s2.substring(0,len2)), 
//					naiveLCS(s1.substring(0, len1 ), s2.substring(0,len2 + 1)));
		}
	}
	
	
	/**
	 * Generalized stringedit solution 
	 * Where change in cost 
	 * 1.match : if i==j return 1 else 0;
	 * 2.indel : 0
	 * 
	 * @param s1
	 * @param s2
	 * @return
	 */
	private int naiveLCS1(String s1,String s2) {
		int I = 2;
		int D = 1;
		int M = 0;
		int len1 = s1.length();
		int len2 = s2.length();
		int[] opt = {0,0,0};
//		System.out.println("s1 : " + s1 + " s2 : " + s2);
		if (len1 <= 0 || len2 <= 0) {
			return 0;
		}
		opt[M] = naiveLCS(s1.substring(0, len1 - 1), s2.substring(0,len2 - 1))
				+ match (s1.charAt(len1 - 1),s2.charAt(len2 - 1));
		opt[I] = naiveLCS(s1.substring(0, len1), s2.substring(0,len2 -1)) + 0;
		opt[D] = naiveLCS(s1.substring(0, len1 - 1), s2.substring(0,len2)) + 0;
		int max = opt[M];
		for (int i=D;i<=I;i++) {
			if (max < opt[i]) {
				max = opt[i];
			} 
		}
		return max;
	}
	

	
	private int match(char s, char d) {
		if(s == d) {
			return 1;
		}
		return 0;
	}




	public static void main(String args[]) {
		LCS lcs = new LCS();
		System.out.println( "naive LCS length : "+ lcs.naiveLCS("ABCDR" , "BAC") );
		System.out.println( "naive LCS length : "+ lcs.naiveLCS1("ABCDR" , "BAC") );
	}
}
