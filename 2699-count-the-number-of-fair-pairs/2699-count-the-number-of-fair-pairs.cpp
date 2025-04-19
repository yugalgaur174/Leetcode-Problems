
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int l=lower-a;
            int h=upper-a;
            auto ln=lower_bound(nums.begin() + i + 1, nums.end(), l);
           
            auto up= upper_bound(nums.begin() + i + 1, nums.end(), h);
            
            ans+=(up-ln);
        }
        return ans;
    }
};