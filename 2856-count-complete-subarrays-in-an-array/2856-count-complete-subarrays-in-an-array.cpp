class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int c=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        c=mpp.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int, int> mpp2;
            int m=0;
            for(int j=i;j<nums.size();j++){
                mpp2[nums[j]]++;
                m=mpp2.size();
                if(m==c){
                    ans+=nums.size()-j;
                    break;
                }
            }
        }
        return ans;
    }
};