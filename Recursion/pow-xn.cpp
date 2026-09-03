//LeetCode 50: Pow(x, n)
//it is basically a divide and conquer. because the value of n can be a bigger number.
//we can do this with squaring x and dividing n by2 . and we can call this as a half 




class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        
      
        if( n < 0 ){
            x = 1/x;
             N = -N;
        }
        if(N == 0) return 1;
        double half = myPow(x , N/2);
       
        if(N%2 != 0){ //if n is an odd number.
            return half * half * x;
        }else{ //if even
            return half * half;

        }
        
    }
};