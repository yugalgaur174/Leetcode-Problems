class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // vector<int> arr(nums.size(),0);
        // arr[0]=nums[0];
        int ans=-1;
        for(int i=1;i<nums.size();i++){
            int a=nums[i-1];
            int b=nums[i];
            int diff=b-a;
            nums[i]=min(a,b);
            ans=max(diff,ans);
        }
        if(ans<=0){
            return -1;
        }
        return ans;
    }
};