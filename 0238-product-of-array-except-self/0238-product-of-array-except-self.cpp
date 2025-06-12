class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        int l=1;
        int r=1;
        for(int i=0;i<nums.size();i++){
            l=l*nums[i];
            left[i]=l;
            r=r*nums[nums.size()-1-i];
            right[nums.size()-i-1]=r;
        }
        int a=right[1];
        int b=left[nums.size()-2];
        
        
        for(int i=1;i<nums.size()-1;i++){
            right[i]=right[i+1]*left[i-1];
        }
            right[0]=a;
            right[nums.size()-1]=b;
        return right;

    }
};