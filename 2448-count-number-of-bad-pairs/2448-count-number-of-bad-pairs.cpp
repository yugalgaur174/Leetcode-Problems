class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long ans=0;
        if(nums.size()<2){
            return 0;
        }
        long long a=nums[0];
        mpp[a]++;
        for(int i=1;i<nums.size();i++){
            a=nums[i]-i;
            long long b=i-mpp[a];
            ans+=b;
            mpp[a]++;
        }
        return ans;
    }
};