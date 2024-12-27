class Solution {
public:
    int mySqrt(int x) {
        // int ans=0;
        for(long long i=0;i<=x;i++){
            if((long long)(i*i)>(long long)x){
                return i-1;
                // ans=i;
                break;
            }
            if((long long)(i*i)==(long long)x)return i;
        }
        return 1;
    }
};