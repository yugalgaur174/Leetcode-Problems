class Solution {
public:
    int coper(int n){
        int a=1;
        while(n>1){
            a*=n;
            n--;
        }
        return a;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto& it:mpp){
            // cout<<
            if(it.second>1){
                ans += (it.second * (it.second - 1)) / 2 * 8;
            }
        }
        return ans;
    }
};