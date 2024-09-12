class Solution {
public:
    int reverse(int x) {
        long long a=0;
        int k=0;
        if(x<0){
            k=1;
        }
        x=abs(x);
        while(x>0){
            a=a*10+x%10;
            if(a>INT_MAX){
                return 0;
            }
//             if (a > 214748364 || (a == 214748364 && x%10 > 7)) {
//     // If reversed is too large, adding any more digits will cause overflow.
//     return 0;
// }
// if (a < -214748364 || (a == -214748364 && x%10 < -8)) {
//     // If reversed is too small, adding any more digits will cause underflow.
//     return 0;
// }
            x=x/10;
        }
        if(k==1){
            return -a;
        }
        return a;
    }
};