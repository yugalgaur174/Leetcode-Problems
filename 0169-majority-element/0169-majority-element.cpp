class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    k++;
                }

            }
            if(k>n/2){
                return nums[i];
            }
        }
        // set <int> t;
        // for(int i=0;i<n;i++){
        //     t.insert(nums[i]);
        // }
        // int m=t.size();
        // for(int)
        return 0;
    }
};