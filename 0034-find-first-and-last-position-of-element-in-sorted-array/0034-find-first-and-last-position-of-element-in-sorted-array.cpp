class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        int l=0, h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target){
                first=m;
                h=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        l=0;
        h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target){
                last=m;
                l=m+1;

            }
            else if(nums[m]>target){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};