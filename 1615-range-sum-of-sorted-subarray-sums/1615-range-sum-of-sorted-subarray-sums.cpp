class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            long long int z=0;
            for(int j=i;j<nums.size();j++){
                z=z+nums[j];
                ans.push_back(z);
            }
        }
        sort(ans.begin(),ans.end());
        long long int sum=0;
        for(int i=left-1;i<right;i++){
            sum=sum+ans[i];
            sum=sum%mod;
        }
        return sum;
    }
};