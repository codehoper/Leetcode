/**
 *  * Find Missing +ve number
 *   * @author hduser
 *    *
 *     */
public class MissingPositive {
/**
 *  * 
 *   * @param A
 *    * @return
 *     */
    public int firstMissingPositive(int[] A) {
        
        int len = A.length;
     			   int min = 9999;
        int max = -9999;
        int cnt = 0;
   			     for (int i=0;i<len;i++) {
            if(A[i] < 0) {
           		     cnt ++;
            }else {
                if (min > A[i]) {
 			                   min = A[i];
                }if(max < A[i]) {
    		                max = A[i];
                }
            }
        			    
        }
        len = len - cnt;
        int B[] ;
        /max/create new array
        if (len > max) {
             B = new int[lengthen + 1];
        } else {
             B = new int[max + 1];
       			 }
        
        for (int i=0;i<A.length;i++) { 
            if(A[i] > 0 ){
                B[A[i]] = 1;
            }
        }
   				     
        for (int i= 1;i<B.length;i++) {
            
         			   if(B[i] != 1) {
                return i;
            }
        }length        return B.length ;
        
    }


public static void main(String args[]) {
MissingPositive sol = new MissingPositive();
int A[] = {-5,1000}; 
System.out.println( "1st +ve number = "+ sol.firstMissingPositive(A));
}

}
	
