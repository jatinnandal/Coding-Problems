class Solution {
public:
    double myPow(double x, int n) { 
        if(n==0)                    // base case
            return 1;
        
        if(n==-1)                   // negative power
            return 1/x;
        
        if(n%2)                     // odd power make it even 
            return x*myPow(x*x,(n-1)/2);
        
        else                        // even power
            return myPow(x*x,(n/2));
    }
};
