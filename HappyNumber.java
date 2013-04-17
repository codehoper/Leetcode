import java.util.HashMap;
import java.util.Map;

class HappyNumber {


	//TO avoid case of "P - problem situation like in linked list"
	//eg number 22
	Map<Integer,Boolean> checkMap = new HashMap<Integer,Boolean> ();
	
    private int squareAndAdd(int num) 
    { 
        int sum = 0;
        while(num > 0) {
            int rem = num % 10;
            num = num /10;
            
            sum += (rem * rem);
        }
        return sum;
          
    }
    private boolean verifyHappy(String input) {
   
        int num = Integer.parseInt(input);
        while(num > 1 && !checkMap.containsKey(num)) {
	  //fill map when we add num
          checkMap.put(num, true);	
           num = squareAndAdd(num);
        }
        if (num == 1) {
           return true;
        }
         return false;
            
    }

    public static void main(String args[]) {
        
//            String input = args[0];
    		String input = "44";
            HappyNumber hp = new HappyNumber();
            boolean isHappy = hp.verifyHappy(input);
            if(true == isHappy) {
                System.out.println("Number is Happy");
            }else {
                System.out.println("Number is not Happy");
            }
    }

}
