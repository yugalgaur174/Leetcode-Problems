class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i=0;
        vector<int> a;
        int max=nums[i];
        for(int j=0;j<nums.size();j++){
            if(nums[j]>max){
                max=nums[j];
            }
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]==max) a.push_back(-1);
            
            else{
                i=(j+1)%nums.size();
                while(nums[i]<=nums[j]){
                    // continue;
                    i=(i+1)%nums.size();
                }
                a.push_back(nums[i]);
                
            }
        }
        return a;
    }
};