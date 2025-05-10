class Solution {
public:
    int find(int start, int end, int target, vector<int> nums){
        if(start==end){
            if(nums[start]==target)return start;
            else return -1;
        }
        int m=(start+end)/2;
        int ans=-1;
        if(nums[m]==target)return m;
        else if(nums[m]>target){
             ans=find(start, m, target, nums);
        }
        else ans=find(m+1, end, target, nums);
        return ans;
    }
    int search(vector<int>& nums, int target) {
        return find(0,nums.size()-1,target,nums);
    }
};