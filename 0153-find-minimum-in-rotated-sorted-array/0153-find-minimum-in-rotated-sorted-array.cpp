class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            ans=min(nums[l],ans);
            ans=min(nums[h],ans);
            ans=min(nums[mid],ans);
             if(nums[l]>=nums[mid]){
                h=mid-1;
            }
            else if(nums[mid]>=nums[h]){
                l=mid+1;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};