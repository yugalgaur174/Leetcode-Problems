class Solution {
public:
    long long mod=1e9+7;
    long long power(long long i, long long exp){
        long long r=1;
        while(exp>0){
            if(exp%2==1){
                r=(r*i)%mod;
            }
            i=(i*i)%mod;
            exp/=2;
        }
        return r;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even=n-odd;
        
        long long a=power(5,even);
        long long b=power(4,odd);
        
        return (a*b)%mod;
              
    }
};