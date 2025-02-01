class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            // cout<<nums[i]<<" "<<nums[i+1]<<endl;
            if(nums[i]%2==1 && nums[i+1]%2==1){
                // cout<<nums[i]<<" "<<nums[i+1]<<endl;
                return false;
            }
            else if(nums[i]%2==0 && nums[i+1]%2==0){
                // cout<<nums[i]<<" "<<nums[i+1]<<endl;
                return false;
            }
        }
        return true;
    }
};