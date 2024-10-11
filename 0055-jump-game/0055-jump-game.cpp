class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums[0]==0) return false;
        int m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i<=m){

            m=max(m,i+nums[i]);
            }
        }
        if(m>=nums.size()-1) return true;
        return false;
    }
};