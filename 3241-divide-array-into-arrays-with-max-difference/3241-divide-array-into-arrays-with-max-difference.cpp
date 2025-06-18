class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i=i+3){
            int a=nums[i];
            int b=nums[i+2];
            if(b-a>k){
                return {};
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};