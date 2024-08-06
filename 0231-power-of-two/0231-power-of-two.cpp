class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int a=1e9+7;
        // int z=100;
        // while(z>0){

        // n=n%a;
        // z--;
        // }
        if(n<=0) return false;
        if((n&(n-1))==0 ) return true;
        return false;
    }
};