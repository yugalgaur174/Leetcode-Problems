class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        long long N=n;
        if(n<0){
            x=1/x;
            N=-N;
        }
        double half = myPow(x, N / 2);
        if(N%2==0) return half*half;
        // if(half*half*x=='inf'){
        //     return 0.00;
        // }
        return half*half*x;
    }
};