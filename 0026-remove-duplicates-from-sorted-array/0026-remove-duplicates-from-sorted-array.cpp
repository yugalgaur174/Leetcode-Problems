class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=nums[0];
        int n=nums.size();
        // int cnt=1;
        vector<int> ans;
        ans.push_back(k);
        for(int i=1;i<n;i++){
            if(k!=nums[i]) {ans.push_back(nums[i]);
            k=nums[i];
            }

        }
        for(int i=0;i<ans.size();i++){
            nums[i]=ans[i];
        }
        return ans.size();
        // int m=1;
        // vector <int> v;
        // v.push_back(nums[0]);
        // for(int i=0;i<nums.size();i++){
        //     if(k!=nums[i]){
        //         v.push_back(nums[i]);
        //         k=nums[i];
        //         m++;
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     nums[i]=v[i];
        // }
        // return m;
    }
};