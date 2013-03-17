/**
*Implement pow(x, n)
**/
class pow {
public:
    
    bool is_even(int x) {
        if ( 0 == x%2 ) return true;
        return false;
    }

   bool is_even1(int x) {
	if((x & 1) == 0) return true;
	return false;

   }
   
    
    //RunTime : O(log n)
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double t = 1;
        //To Handle -ve power cases
        if (n < 0 ) { n = -n ; x = 1/x;}
        //Base case
        if (n == 0) { return t ;}
        
        //store output
        if ( true == is_even (n) ) {
            t = pow(x,n/2);
            t = t*t;
        }else {
            t = x * pow(x,n-1);
        }
        
        return t;
    }

   //optimized version with same complexity as pow();
   double pow1(const double base,int n) {
	 if(n == 0) return 1;
	double ret;
	 else if(n%2 == 0) {
	 	ret = pow1(base,n/2);
		return ret * ret;
	 }else {
	 	ret = pow1(base,(n-1)/2);
		return base * ret * ret;
	 }
   }
};
