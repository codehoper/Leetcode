public class StringEditRec {
	/**
	 * see the pages
	 */
	static int INSERT = 1;
	static int DELETE = 2;
	static int MATCH = 0;
	
	private int RecEditDist(String s,String t) {
		
		int[] opt= new int [3];
		int lowest_cost;
		
		if (s.length() == 0) {
			return (t.length());
		}
		if (t.length() == 0) {
			return (s.length());
		}
		opt[MATCH] = RecEditDist(s.substring(0,s.length()-1), t.substring(0,t.length()  -1)) 
					+ match(s.charAt(s.length() -1 ),t.charAt(t.length()-1));
		opt[INSERT] = RecEditDist(s.substring(0,s.length()-1),t) + 1; 
		opt[DELETE] = RecEditDist( s,t.substring(0,t.length()-1)) + 1;
		lowest_cost = opt[MATCH];
		
		for (int i= INSERT;i<=DELETE;i++) {
			if (lowest_cost > opt[i]) {
				lowest_cost = opt[i];
			}
		}
		return lowest_cost;
	}
	
	private int match(char c, char d) {
		if(c == d) return 0;
		else return 1;
	}

	public static void main(String args[]) {
		
		String s = "ramayan";
		String t = "mahabharat";
		StringEditRec rect = new StringEditRec();
		int no = rect.RecEditDist(s, t);
		System.out.println("Edit distnce "+no);
		
//		System.out.println(s.substring(0,s.length() -1));
		
	}

}