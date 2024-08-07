class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0){
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }
        if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        if(dividend==INT_MAX && divisor==-1){
            return INT_MIN+1;
        }
        long long ad=abs((long long)dividend);
        long long adi=abs(divisor);
        bool nega=(dividend<0)^(divisor<0);
        int quotient=0;
        
        while(ad>=adi){
            ad-=adi;
            quotient++;
        }
        if(nega){

        return -quotient;
        }
        return quotient;
    }
};