
/**
 * Calculates power Recursively and iteratively
 * @author 
 *
 */
public class Pow {

	int pow(int x,int n) {

		//base base
		int sum = 0;
		if (n == 0) return 1;
		if (n == 1) return x;
		if(n % 2 == 0) {
			sum = pow(x,n/2) * pow(x,n/2);
		}else {
			sum = pow(x,n/2) * pow(x,n/2) * x;
		}
		return sum;
	}

	int pow1(int x,int n) {

		//base base
		int sum = 0;
		if (n == 0) return 1;
		if (n == 1) return x;
		int mem = pow(x,n/2);
		if(n % 2 == 0){
			sum = mem * mem;	 //don't use +
		}else {
			sum = mem * mem * x;	
		}
		return sum;
	}
	
	/**
	 * Interative version
	 */
	double iterPow2(double x, int n) {
		double result = 1.0;
		double step = x;
		for (int i = Math.abs(n); i > 0; i /= 2) {
			if ((i & 1) == 1) {
				result *= step;
			}
			step *= step;
		}
		result = (n < 0 ? 1 / result : result);
		return result;
	}
	
	int iterPow(int x,int n) {
		
		int sum = x;
		if(n == 0) return 1;
		for (int i = 1 ;i< n; i++) {
			sum = sum * x;
		}
		
		return sum;
	}
	
	
	
	public static void main(String args[]) {
		Pow pow = new Pow();
		System.out.println("2^5 = "+pow.pow(2, 5)+"\n2^6 = "+pow.pow(2, 6));
		System.out.println("2^7 = "+pow.pow1(2, 7)+"\n2^6 = "+pow.pow1(2, 6));
		System.out.println("2^2 = "+pow.iterPow(2, 1)+"\n2^4 = "+pow.iterPow(2, 4));
	}

}
