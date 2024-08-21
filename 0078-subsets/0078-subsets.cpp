class Solution {
public:
    void printF(int ind, vector<int>& ds, vector<int>& nums,int n,vector<vector<int>>& a){
        if(ind==n){
            if(count(a.begin(),a.end(),ds)==0){
                a.push_back(ds);
                if(ds.size()==0 && count(a.begin(),a.end(),ds)==0){
                    a.push_back(ds);
                }
            }
            return;
        }
        ds.push_back(nums[ind]);
        printF(ind+1,ds,nums,n,a);
        ds.pop_back();
        printF(ind+1,ds,nums,n,a);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        int ind;
        int n=nums.size();
        vector<vector<int>> a;
        printF(ind,  ds, nums,n,a);
        return a;
    }
};