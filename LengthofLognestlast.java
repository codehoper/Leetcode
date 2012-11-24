public class Solution {
    public int lengthOfLastWord(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
         String[] arr = s.split(" ");
         int len = arr.length;
         int i = len;
         if(len >= 1) {
             return arr[i-1].length();
         }else {
              return 0;
         }
        
    }
    
    
    public static void main(String args[]) {
    	Solution sol = new Solution();
    	System.out.println(" length ::: "+sol.lengthOfLastWord(""));
    }
    
}