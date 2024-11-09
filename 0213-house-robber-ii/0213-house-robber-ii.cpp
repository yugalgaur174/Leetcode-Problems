class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        return max(robber(nums, 0,n-2), robber(nums,1, n-1));
    }

    int robber(vector<int> & nums, int start, int end){
        int prev=0;
        int prev2= 0;
        for(int i=start;i<end+1;i++){
            int curr=nums[i];
            int take= curr+prev2;
            int nottake=prev;
            prev2=prev;
            prev=max(take, nottake);
            
        }
        return prev;
    }
};