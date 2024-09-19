class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& m:mpp){
            pq.push(make_pair(m.first,m.second));
        }
        while(!pq.empty()){
            int start=pq.top().first;
            vector<pair<int,int>> temp;
            for(int i=0;i<k;i++){
                if(pq.empty()|| pq.top().first!=start+i){
                    return false;
                }
                else{
                    auto curr=pq.top();
                    pq.pop();
                    temp.push_back({curr.first,curr.second-1});
                }
            }
            for(auto& i:temp){
                if(i.second>0){
                    pq.push(i);
                }
            }
        }
        return true;
        
    }
};