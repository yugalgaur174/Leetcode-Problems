class Solution {
public:
    void findd(vector<int>&nums,vector<vector<int>>& arr, vector<int>& ds, vector<int>&mark){
        if(ds.size()==nums.size()){
            arr.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mark[i]){
                ds.push_back(nums[i]);
                mark[i]=1;
                findd(nums,arr,ds,mark);
                mark[i]=0;
                ds.pop_back();

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        // unordered_map
        vector<int> ds;
        vector<int> mark(nums.size(), 0);
        
        findd(nums,arr,ds,mark);
        return arr;
    }
};