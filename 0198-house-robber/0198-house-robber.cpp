class Solution {
public:
    int ans(int n,vector<int> nums,vector<int>&dp){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+ans(n-2,nums, dp);
        int notpick=0+ans(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return ans(n-1,nums,dp);
    }
};