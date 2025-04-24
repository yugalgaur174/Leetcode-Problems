class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int c=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==1){
                c++;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int, int> mpp2;
            int m=0;
            for(int j=i;j<nums.size();j++){
                mpp2[nums[j]]++;
                if(mpp2[nums[j]]==1){
                    m++;
                }
                if(m==c){
                    ans+=nums.size()-j;
                    break;
                }
            }
        }
        return ans;
    }
};