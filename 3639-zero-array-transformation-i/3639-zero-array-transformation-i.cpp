class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> mark(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            mark[l]+=1;
            if(r<mark.size()-1){
                mark[r+1]-=1;
            }
        }
        for(int i=1;i<nums.size();i++){
            mark[i]+=mark[i-1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]-=mark[i];
            if(nums[i]>0)return false;
        }
        return true;
    }
};