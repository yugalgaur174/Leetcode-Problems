class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int> > mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto & it: mpp){
            if(it.second.size()>1){
                for(int i=0;i<it.second.size();i++){
                    for(int j=i+1;j<it.second.size();j++){
                        if(it.second[i]*it.second[j]%k==0){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};