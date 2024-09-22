class Solution {
public:
    void find(int i,vector<int>& nums,set<vector<int>> &ans, vector<int> & ds){
        if(i==nums.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        find(i+1,nums,ans,ds);
        ds.pop_back();
        find(i+1,nums,ans,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        set<vector<int>> ans;
        find(0,nums,ans,ds);
        vector<vector<int>> a(ans.begin(),ans.end());
        
        return a;
    }
};