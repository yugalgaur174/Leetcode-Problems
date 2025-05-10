class Solution {
public:
    int find(int start, int end, int target, vector<int> nums){
        int m=(start+end)/2;
        if(nums[m]==target)return m;
        if(start>end){
            return -1;
        }
        int ans=-1;
        if(nums[m]>target){
             ans=find(start, m-1, target, nums);
        }
        else ans=find(m+1, end, target, nums);
        return ans;
    }
    int search(vector<int>& nums, int target) {
        return find(0,nums.size()-1,target,nums);
    }
};