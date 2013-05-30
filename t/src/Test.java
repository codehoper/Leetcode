
public class Test {


	private String revString(String str) {
		int len = str.length();
		String str1= "";
		for(int i = len ;i >= 0;i--) {
			 str1 += str.substring(0, i);
		}
		return str1;
	}
	
	private int convertHextoInt(String str) {
		str = str.toLowerCase();
		char [] arr = str.toCharArray();
		int len = arr.length;
		int sum = 0;
		for (int i= len-1;i>=0;i--) {
			int unit = (arr[i] - '0'); 
			if(unit > 9) {
				unit = arr[i] - 'a';
				unit += 10;
			}
			sum +=  unit * Math.pow(16, len-i-1);
		}
		return (sum);
	}


	public static void main(String args[]) {
		Test t = new Test();
		System.out.println("o/p = \n"+t.convertHextoInt("BEEF1"));
		
		System.out.println(t.revString("Hello"));
	}
}
