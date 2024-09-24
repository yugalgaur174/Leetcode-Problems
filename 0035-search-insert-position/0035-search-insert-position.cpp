class Solution {
public:
    int ans=-1;
    void findd(int low,int high, vector<int> nums, int target){
        if(low>high) return ;
        int mid=(low+high)/2;
        if(nums[mid]<target){
            ans=mid;
            findd(mid+1,high,nums,target);
        }
        else{
            findd(low,mid-1,nums,target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        findd(low, high,nums,target);
        return ans+1;
    }
};