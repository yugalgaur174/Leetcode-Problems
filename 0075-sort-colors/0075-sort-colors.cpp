class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            int j=i-1;
            int x=nums[i];
            while(j>=0&&nums[j]>x ){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=x;
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
    }
};