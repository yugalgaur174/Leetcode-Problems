class Solution {
public:
    void permu(int ind,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(a);            }
        return;
        }
        if(candidates[ind]<=target){
            a.push_back(candidates[ind]);
            permu(ind,target-candidates[ind],candidates,ans,a);
            a.pop_back();
        }
        permu(ind+1,target,candidates,ans,a);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        permu(0,target,candidates,ans,a);
        return ans;
    }
};