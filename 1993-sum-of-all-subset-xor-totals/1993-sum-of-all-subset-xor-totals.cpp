class Solution {
public:
    int ans=0;
    void calc(int i, vector<int> nums, int currxor){
        if(i==nums.size()){
            ans+=currxor;
            return;
        }
        calc(i+1, nums, currxor^nums[i]);
        calc(i+1, nums, currxor);

    }
    int subsetXORSum(vector<int>& nums) {
        calc(0, nums, 0);
        return ans;
    }
};