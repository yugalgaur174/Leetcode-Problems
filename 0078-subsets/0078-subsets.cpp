class Solution {
public:
    set<vector<int>> arr;
    void check(vector<int>& a, int n, vector<vector<int>> & ans, int i, vector<int> nums){
        if(i==n){
            arr.insert(a);
            return;
        }
        a.push_back(nums[i]);
        check(a,n,ans,i+1,nums);
        a.pop_back();
        check(a,n,ans,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> a;
        int n=nums.size();
        check(a,n,ans,0,nums);
        for(auto &it:arr){
            ans.push_back(it);
        }
        return ans;
    }
};