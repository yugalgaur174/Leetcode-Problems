class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int d=abs(nums[i]-nums[(i+1)%nums.size()]);
            if(d>ans){
                ans=d;
            }
        }
        return ans;
    }
};