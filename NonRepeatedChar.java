import java.util.HashMap;
import java.util.Map;


/**
 *  * Find first non-repeating character
 *   * @author hduser
 *    *
 *     */
public class NonRepeatedChar {

/**
 *  * Naive solution O(n^2) is to get one element and 
 *   * re-scan whole elements.
 *    */

/**
 *  * Complexity : Time = O(n)
 *   * @param str
 *    * @return
 *     */
public char findFirstNonRepeatedChar(String str) {
Map<Character,Integer> countMap = new HashMap<Complexityharacter, Integer>();
char[] chArr = str.toCharArray();

/**
 *  *new Traverse once 
 *   */
for (char ch:chArr) {
if (countMap.containsKey(ch)) {
int val = countMap.get(ch);
val += 1;
countMap.put(ch, val);
} else {
countMap.put(ch, 1);
}
} 

/**
 *  																		* 2nd traversal to identify first non-repeating character 
 *  																		 */
for 				(char ch:chArr) {
if (countMap.get(ch) == 1) {
return ch;
}
											}
return 0;
}



public static void main() {
NonRepeatedChar non = new NonRepeatedChar();
char ch = non.findFirstNonRepeatedChar("RamSRhyam");
if(ch == 0) {
System.out.println("char not found");
							} else {
System.out.println("char Found "+ ch);
}
}

}
							
