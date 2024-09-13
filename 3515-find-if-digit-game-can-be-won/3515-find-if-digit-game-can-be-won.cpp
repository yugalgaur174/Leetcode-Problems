class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>9) b+=nums[i];
            else a+=nums[i];
        }
        if(a==b) return false;
        return true;
    }
};