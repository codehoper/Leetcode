public class NumberValidation {
	
	/**
	 * Consider cases like 12e10 => number ,12e3=> not number,"   " => not a number," 0.1 "=>number 
	 * 	"." => not a number,"++3" => not ,"+3" => no
	 * @param s
	 * @return
	 */
	public boolean isNumber(String s) {
		int len = s.length();
		if(len == 0) return false;
		for(int i=0;i<len;i++) {
			 char n = s.charAt(i);
			 if(n == ' ') continue;
			 int t = n - '0';
			 if(!(t >= 0 && t<= 9)) return false;
		}
		return true;

	}
	
	public static void main(String args[]) {
		Validation val = new Validation();
		boolean isNumber = val.isNumber("00");
		if(isNumber == true) {
			System.out.println("Is a number");
		}else {
			System.out.println("Not a number ::");
		}
	}

}
