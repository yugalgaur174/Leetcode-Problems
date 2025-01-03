class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long r=0;
        long long ans=0;
        for(int i=nums.size()-1;i>0;i--){
            r+=nums[i];
            sum-=nums[i];
            cout<<r<<" "<<sum<<endl;
            if(sum>=r){
                ans++;
            }
        }
        return ans;
    }
};