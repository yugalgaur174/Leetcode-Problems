class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto& it: mpp){
            pq.push({it.second, it.first});
        }
        while(k>0 && !pq.empty()){
            auto a=pq.top();
            ans.push_back(a.second);
            k--;
            pq.pop();
        }
        return ans;
    }
};