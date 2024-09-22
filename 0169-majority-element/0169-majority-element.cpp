class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cl=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cl=nums[i];
                cnt=1;
            }
            else if(cl==nums[i]){
                cnt++;
            }
            else if(cl!=nums[i]){
                cnt--;
            }
        }
        return cl;
        // for(int i=0;i<n;i++){
        //     int k=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[i]==nums[j]){
        //             k++;
        //         }

        //     }
        //     if(k>n/2){
        //         return nums[i];
        //     }
        // }
        // set <int> t;
        // for(int i=0;i<n;i++){
        //     t.insert(nums[i]);
        // }
        // int m=t.size();
        // for(int)
        return 0;
    }
};