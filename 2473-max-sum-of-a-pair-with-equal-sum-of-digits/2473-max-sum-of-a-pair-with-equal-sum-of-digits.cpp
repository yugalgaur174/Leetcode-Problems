class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int> > mpp;
        unordered_map<int, int> mark;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int b=0;
            while(a>0){
                b+=a%10;
                a/=10;
            }
            mark[b]++;
            mpp[b].push(nums[i]);
        }
        int ans=-1;
        for(auto& it:mark){
            if(it.second>1){
                int c=mpp[it.first].top();
                mpp[it.first].pop();
                int d=mpp[it.first].top();
                int e=c+d;
                ans=max(ans,e);
            }
        }
        return ans;
    }
};