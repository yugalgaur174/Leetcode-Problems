class Solution {
public:
    double power(double x, long long n) {
        if(n == 0) {
            return 1;
        }
        double half=power(x, n / 2);
        if(n%2==0){
            return half*half;
        }
        else{
            return x*half*half;
        }
      
        
        
    }

    double myPow(double x, int n) {
        if(n == 1) return x;
        if(n == -1) return 1.0 / x;

        long long exp = n; 
        if(exp < 0) {
            return 1.0 / power(x, -exp);
        }
        return power(x, exp);
    }
};
