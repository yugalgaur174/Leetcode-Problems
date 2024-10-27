class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(a>nums[i])a=nums[i];
            if(b<nums[i])b=nums[i];
        }
        return gcd(a,b);
    }
};