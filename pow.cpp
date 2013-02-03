/**
*Implement pow(x, n)
**/
class pow {
public:
    
    bool is_even(int x) {
        if ( 0 == x%2 ) return true;
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
};