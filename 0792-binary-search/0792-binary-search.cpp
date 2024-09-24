class Solution {
public:
    int ans=-1;
    void findd(int high, int low, int target, vector<int> & nums){
        if(low>high) return;
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans=mid;
            return;
        }
        else if(nums[mid]>target){
            findd(mid-1,low,target,nums);
        }
        else{
            findd(high,mid+1,target, nums);
        }
    }
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        if(nums[low])
        findd(high,low,target,nums);
        return ans;
    }
};