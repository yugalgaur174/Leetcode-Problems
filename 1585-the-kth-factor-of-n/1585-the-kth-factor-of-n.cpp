class Solution {
public:
    int kthFactor(int n, int k) {
        if(k>n) return -1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                cnt++;
                if(cnt==k){
                    return i;
                }
            }
        }
        return -1;
    }
};