class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)ans++;
        }
        int a=0;
        int b=nums.size()-1;
        while(a<b){
            while(nums[a]!=val && a<b){
                a++;
            }
            while(nums[b]==val && a<b){
                b--;
            }
            swap(nums[a],nums[b]);
        }
        return ans;
    }
};