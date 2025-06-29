class Solution {
public:
    vector<vector<int>> ans;
    void making(int i,vector<int> candidates, vector<int>& arr, int target, int curr){
        if(i==candidates.size()){
            return;
        }
        if(curr==target){
            ans.push_back(arr);
            return;
        }
        if(curr>target){
            return;
        }
        arr.push_back(candidates[i]);
        making(i, candidates, arr, target, curr+candidates[i]);
        arr.pop_back();
        making(i+1, candidates, arr, target, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        making(0,candidates,arr ,target,0);    
        return ans;
    }
};