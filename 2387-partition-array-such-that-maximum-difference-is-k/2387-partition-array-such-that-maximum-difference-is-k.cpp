class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=1;
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            int b=nums[i];
            int c=b-a;
            if(c>k){
                a=nums[i];
                ans++;
            }   
        }
        return ans;
    }
};