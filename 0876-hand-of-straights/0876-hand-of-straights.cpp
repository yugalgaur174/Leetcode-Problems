class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;

        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto& m:mpp){
            pq.push({m.first,m.second});
        }
        while(!pq.empty()){
            auto no=pq.top();
            vector<pair<int,int>> temp;
            for(int i=0;i<k;i++){
                if(pq.empty()|| pq.top().first!=no.first+i){
                    return false;
                }
                auto curr=pq.top();
                pq.pop();
                temp.push_back({curr.first,curr.second-1});
            }
            for(auto & m:temp){
                if(m.second>0){
                    pq.push(m);
                }
            }
        }
        return true;
    }
};