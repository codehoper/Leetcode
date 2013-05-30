import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Main {

//Not backtracking simple recursion
	
    // print N! permutation of the characters of the string s (in order)
    public  static void perm1(String s) { 
    	perm1("", s); 
    }
    
    private static void perm1(String prefix, String s) {
        int N = s.length();
        if (N == 0) System.out.println(prefix);
        else {
            for (int i = 0; i < N; i++)
               perm1(prefix + s.charAt(i), s.substring(0, i) + s.substring(i+1, N));
        }

    }
    
	/**
	 * Use recursion.
	1.Try each of the letters in turn as the first letter and
	 then find all the permutations of the remaining letters using a recursive call.
	2.The base case is when the input is an empty string
	 the only permutation is the empty string.

	 * @param str
	 * @param index
	 * @param strList
	 */
	private void recPermutation(StringBuffer str,int index,List<String> strList) {

		if(index == 0) {
			strList.add(str.toString());
		} else {
			recPermutation(str, index -1, strList);  //traverse
			int currPos = str.length()-index;
			for (int i = currPos+1; i < str.length(); i++) {//start swapping all other chars with current first char
				swap(str,currPos, i);
				recPermutation(str, index-1,strList); //for saving in list
				swap(str,i, currPos);//restore back my string buffer
			}

		}
	}
	
	private  static void swap(StringBuffer str, int pos1, int pos2){
		char t1 = str.charAt(pos1);
		str.setCharAt(pos1, str.charAt(pos2));
		str.setCharAt(pos2, t1);
	} 


	public static void main(String args[]) {
		Map<String,Integer> opMap = new HashMap<String, Integer>();
		Main m = new Main();
		StringBuffer strBuffer = new StringBuffer("abc");
		List<String> strList = new ArrayList<String>();
		
		m.recPermutation(strBuffer,strBuffer.length(),strList);
		System.out.println("size "+ strList.size());
		for(String s:strList){
			System.out.println(s);
		}

		for (String str : opMap.keySet()) {
			System.out.print( str +" \t");
		}

	}

}
