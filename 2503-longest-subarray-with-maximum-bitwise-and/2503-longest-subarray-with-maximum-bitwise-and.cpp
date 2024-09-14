class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        int max_length=0,cl=0;
        for(int num:nums){
            if(num==maxx) {
                cl++;
                max_length=max(max_length,cl);
            }
            else{
                cl=0;
            }
        }
        return max_length;
        // int max=0,b=0;
        // for(int i=0;i<nums.size();i++){
        //     int a=nums[i];
        //     for(int j=i;j<nums.size();j++){
        //         a=a&nums[j];
        //         if(a>b || (a==b&& max<(j-i+1))){
        //             b=a;
        //             max=(j-i+1);
        //         }
        //     }
        // }
        // return max;
        // return 0&5;
    }
};