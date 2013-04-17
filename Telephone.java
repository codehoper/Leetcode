import java.util.ArrayList;
import java.util.List;

public class Telephone {
	
	//Used to generate candidates
	
	private char[][] dict = {{'0'},
			{'1'},
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v','w'},
			{'w','x','y','z'}
	};

	public Telephone() {

	}

	//Perform backtracking with input

	private void  recPermute(String input,String result,List<String> output) {

		if(input.length() == 0) {
			output.add(result);
//			System.out.println("" + result);
		}else {
			int currentChar = input.charAt(0) - '0' ;
//			System.out.println(currentChar);
//			//remainderString acts as input for the next recPermute
			String remainderString = input.substring(1); //leave 1st charcter extract other
		
			//dict[currentChar].length = number of candidates
			//Character.toString(dict[currentChar][i]) = candidate
			for(int i=0;i<dict[currentChar].length;i++) {
				if(i==0) {
					result += (Character.toString(dict[currentChar][i]));
				}else {
				 	//Remove the last character 
					//TO avoid condition to append strings at last 
					//Use (length - 1) : to empty position for next candidate
				 	String temp = result.substring(0,result.length()-1);
				 	temp += (Character.toString(dict[currentChar][i]));
				 	result = temp;
				}
//				result += (Character.toString(dict[currentChar][i]));
				recPermute(remainderString,result,output);
			}

		}

	}



	public static void main(String args[]) {
		Telephone tel = new Telephone();
		for (int i=0;i<9;i++) {
			//			System.out.println(""+tel.dict[i].length);
		}
		String c = "abc".substring(2,3);
		//	     System.out.println(""+c);
		List<String> strList = new ArrayList<String>();
		tel.recPermute("415520","" ,strList);
//		System.out.println("size :"+strList.size());
		
		for(String str:strList) {
			System.out.print(str + "\t");
		}
	}

}
