class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // return 3^3;
         while(nums[0]!=nums[nums[0]])
        {
           swap( nums[0],nums[nums[0]]);
        }
        return nums[0];
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if((nums[i]^nums[i+1])==0){
        //         return nums[i];
        //     }
        // }
        // return 0;
    }
};