class Solution {
public:
    // int ans=0;
    int calc(int i, vector<int> nums, int currxor){
        if(i==nums.size()){
            
            return currxor;
        }
        int take=calc(i+1, nums, currxor^nums[i]);
        int nottake=calc(i+1, nums, currxor);
        return take+nottake;
    }
    int subsetXORSum(vector<int>& nums) {
        return calc(0, nums, 0);
        // return ans;
    }
};