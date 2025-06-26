class Solution {
public:
    vector<int> dp;
    int climbing(int n) {
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=climbing(n-1)+climbing(n-2);
    }
    int climbStairs(int n) {
        dp= vector<int>(n+1,-1);
        return climbing(n);
    }
};