class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=0;
        while(low<high){

            int mid=(low+high)/2;
            // if(mid==low) break;
            if(nums[high]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid;
            }
            ans=low;
        }
        return nums[low];
    }
};