
public class Strings {



	/**
	 * Verify string is palindrome or not
	 * @param str
	 * @return
	 */
	private boolean isPalindrome(String str) {
		int low = 0;
		int high = str.length() - 1;
		while(low < high) {
			if(str.charAt(low) != str.charAt(high)) {
				return false;
			}
			low ++;
			high--;
		}
		return true;
	}
	
	/**
	 * Verify string in anagram or not
	 * @param str
	 * @param dest
	 * @return
	 */
	private boolean isAnagram(String str,String dest) {
		
			if(str.length() != dest.length()) {
				return false;
			}
			
			char arr[]  = str.toCharArray();
			char arr1[] = dest.toCharArray();
			
			int len = arr.length;
			for(int i=0;i<len;i++) {
				if(arr[i] != arr1[i])
					return false;
			}
		return true;
	}
	
	/**
	 * Reverse string in place
	 * @param str
	 * @return
	 */
	private String revString(String str) {

		char arr[] = str.toCharArray();
		int low = 0;
		int high = arr.length - 1;
		
		while(low < high) {
			char temp = arr[high];
			arr[high] = arr[low];
			arr[low] = temp; 
			low++;
			high--;
		}
		
	 return arr.toString();
	 
	}
	
	
	/**
	 * 
	 * @param src
	 * @param part
	 * @return
	 */
	private boolean isSubString(String src,String part) {
		
		if (!src.contains(part))
			return false;
		
		return true;
		
	}
	
	/**
	 * 1.Assert both strings S1 and S2 are of same length. If not, return False.
	 * 2.Check and see if S1 is a substring of S2+S2. 
	 * If so, return True, else return False.
	 * @param src
	 * @param dest
	 * @return
	 */
	private boolean isRotation(String src,String dest) {
		
		if(src.length() != dest.length()) {
			return false;
		}
		
		if(!isSubString(src+src, dest)) {
			return false;
		}
		
		return true;
		
		
	}
	
	
	//Edit distance calculation
	//Recursive
	//	OPT(i,j) = MAX(i,j) iff i/j = 0
	//			 = MIN { OPT(i-1,j) + 1 ;
	//			 		 OPT(i,j-1) + 1;
	//			 		 OPT(i-1,j-1) + MATCH(i,j)
	//			 	   }
	//	MATCH (i,j) = 0 iff A[i] == A[j]
	//				= 1 iff A[i] != A[j]

	/**
	 * This distance is shortest distance
	 * @param i
	 * @param j
	 * @return
	 */
	private int editRecDistance(String i,String j) {
		
		int a = i.length();
		int b = j.length();
		if(a == 0 ||b == 0) {
			return Math.max(a, b);
		}else {
			int min,t;
			min = editRecDistance(i.substring(0,a - 1), j.substring(0,b - 1))
		                         + match(i.charAt(a - 1),
		                        		 j.charAt(b - 1));
		    t = Math.min(editRecDistance(i.substring(0,a-1),j) + 1,
		    		 editRecDistance(i,j.substring(0,b-1)) + 1);
			min = Math.min(min, t);
			return min;
		}
		
	}
	
	/**
	 * This is maximum length of longest common subsequence.
	 * @param i
	 * @param j
	 * @return
	 */
	private int calRecLCSlength(String i,String j) {
		int a = i.length();
		int b = j.length();
		if(a == 0 || b == 0) {
			return 0;
		}else {
			int max1 = calRecLCSlength(i.substring(0, a-1),j.substring(0,b-1))
					+ match1(i.charAt(a-1),j.charAt(b-1));
			int max2 = Math.max(calRecLCSlength(i.substring(0,a-1), j), 
					calRecLCSlength(i, j.substring(0,b-1)));
			
			return Math.max(max1, max2);
		}
		
	}
	/**
	 * Match cost for LCS	
	 * @param s
	 * @param t
	 * @return
	 */
	private int match1(char s, char t) {
		if(s == t)
		return 1;
		else return 0;
	}

	/**
	 * Match cost for edit distance
	 * @param s
	 * @param t
	 * @return
	 */
	private int match(char s, char t) {
		if(s == t)
		return 0;
		else return 1;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 String s = "ramayan";
		 String t = "mahabharat";
		 Strings rect = new Strings();
		 System.out.println("Distance  = " + rect.editRecDistance(s, t));
		 System.out.println("LCS = "+rect.calRecLCSlength(s, t));
	}

}
