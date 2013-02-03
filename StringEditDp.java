package com.ub.dynamic;

public class StringEditDp {

	class table {
		int cost;
		int parent;
	}
	static int MATCH = 0;
	static int INSERT = 1;
	static int DELETE = 2;

	private void stringComapre(String s,String t) {

		int slen = s.length();
		int tlen = t.length();
		table m[][] = new table [slen][tlen];
		for (int i=0;i<slen;i++) {
			for (int j=0;j<tlen;j++) {
				m[i][j] = new table();
			}
		}
		init_row(m,slen);
		init_col(m,tlen);

		if(slen == 0) {
			m[slen -1 ][tlen -1].cost = tlen; 
		}else if (tlen == 0) {
			m[slen - 1][tlen -1].cost = slen;
		}

		int opt[] = new int [3];
		int minCost;
		int operation;
		for(int i=1;i<slen;i++) {
			for (int j=1;j<tlen;j++) {
				opt[MATCH] = m[i-1][j-1].cost + match(s.charAt(i),t.charAt(j));
				opt[INSERT] = m[i-1][j].cost + 1;
				opt[DELETE] = m[i][j-1].cost + 1;
				minCost = opt[MATCH];
				operation = MATCH;
				for(int r=INSERT;r<=DELETE;r++) {
					if(minCost > opt[r]) {
						minCost = opt[r];
						operation = r;
					}
				}
				m[i][j].cost = minCost;
				m[i][j].parent = operation;
			}
		}		

		printMatrix(m,true);
		System.out.print("\n");
		printMatrix(m,false);
		printPath(m,s,t);
		//		System.out.println(m[s.length() - 1][t.length() -1].cost);
	}

	private void printMatrix(table[][] m,boolean isCost) {
		int l = m.length;
		int w = m[0].length;
		for (int i=0;i<l;i++) {
			for(int j=0;j<w;j++) {
				if(isCost) 
				System.out.print(m[i][j].cost + " ");
				else 
				System.out.print(m[i][j].parent + " ");
			}
			System.out.print("\n");
		}

	}

	private int match(char s, char t) {
		if(s == t) return 0;
		return 1;
	}

	/**
	 * Initialization start from zero while comparing starts from 1
	 * @param m
	 * @param tlen
	 */
	private void init_col(table[][] m, int tlen) {
		for (int i=0;i<tlen;i++) {
			m[0][i].cost = i;
			if(i != 0) {
				m[0][i].parent = DELETE;
			}else {
				m[0][i].parent = -1;
			}
		}

	}
	private void init_row(table[][] m, int slen) {
		for (int i=0;i<slen;i++) {
			m[i][0].cost = i; 
			if(i != 0) {
				m[i][0].parent = INSERT;
			}else {
				m[i][0].parent = -1;
			}
		}

	}


	void printPath(table m[][],String s,String t) {
		int slen = s.length();
		int tlen = t.length();
		if(m[slen -1][tlen -1].parent == -1) {
			return;
		}else if(m[slen -1 ][tlen - 1].parent == MATCH) {
			printPath(m, s.substring(0,slen -1), t.substring(0,tlen -1));
			match_out(s,t);
			return;
		}else if(m[slen -1][tlen -1].parent == INSERT) {
//			printPath(m, s, t.substring(0,tlen - 1));
			printPath(m, s.substring(0,slen -1), t);
			System.out.print("I");
			return;
		}else if(m[slen-1][tlen-1].parent== DELETE) {
//			printPath(m, s.substring(0,slen -1), t);
			printPath(m, s, t.substring(0,tlen - 1));
			System.out.print("D");
			return;
		}	
	}

	private void match_out(String s, String t) {
		// TODO Auto-generated method stub
		if(s.charAt(s.length() -1) == t.charAt(t.length() -1)) {
			System.out.print("M");
		}else {
			System.out.print("S");
		}
	}

	public static void main(String args[]) {
		String s = "ramayan";
		String t = "mahabharat";
		s = " " + s;
		t = " " + t;
		StringEditDp strdy = new StringEditDp();
		strdy.stringComapre(s, t);
	}

}