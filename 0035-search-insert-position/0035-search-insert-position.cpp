class Solution {
public:
    
    int searchInsert(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int ans=nums.size();
        while(l<=h){
            int m=(l+h)/2;
            
            if(nums[m]>=target){
                cout<<ans<<endl;
                ans=m;
                h=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
        }
        return ans;
    }
};