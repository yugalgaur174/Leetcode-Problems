class Solution {
public:
    int find(int l, int h, int target, vector<int> & nums){
        if(l>h)return -1;
        int mid=(l+h)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target){
            return find(l, mid-1, target, nums);
        }
        return find(mid+1, h, target, nums);
    }
    int search(vector<int>& nums, int target) {
        return find(0, nums.size()-1, target, nums);
    }
};