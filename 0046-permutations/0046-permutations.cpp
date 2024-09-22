class Solution {
public:
    void findd(int i,vector<int>& nums,vector<vector<int>> &ans, vector<int> &ds){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            ds.push_back(nums[i]);
            findd(i+1,nums,ans,ds);
            ds.pop_back();
            swap(nums[j],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        int i=0;
        findd(i,nums,ans,ds);
        return ans;
    }
};