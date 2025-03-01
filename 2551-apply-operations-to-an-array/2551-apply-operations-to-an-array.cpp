class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] ){
                nums[i]*=2;
                nums[i+1]=0;
            }
                cout<<"nums[i] ="<<nums[i]<<endl;
            
        }
        int n=nums.size();
         vector<int> result;
        for (int num : nums) {
            if (num != 0) result.push_back(num);
        }
        while (result.size() < n) result.push_back(0);
        return result;
    }
};