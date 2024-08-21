class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long z=0;
        for(int i=0;i<n;i++){
            int maxval=nums[i];
            int minval=nums[i];
            for(int j=i;j<n;j++){
                maxval=max(maxval,nums[j]);
                minval=min(minval,nums[j]);
                z=z+maxval-minval;
            }
        }
        return z;
    }
};