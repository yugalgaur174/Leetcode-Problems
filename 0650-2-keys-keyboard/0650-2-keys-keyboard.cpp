class Solution {
public:
int minSteps(int n) {
        int ans = 0;
        int prime = 2;
        while(n > 1){
            while(n % prime == 0){
                n /= prime;
                ans += prime;
            }
            prime++;
        }
        
        return ans;
    }
    // int minSteps(int n) {
    //     // return n;
    //     int z=1;
    //     int sum=1;
    //     int count=0;
    //     while(sum!=n){
    //         if(n%z==0){
    //             z++;
    //             sum+=z;
    //             count++;
    //         }
    //         sum+=z;
    //         n-=sum;
    //     }
    //     return count;
    // }
};