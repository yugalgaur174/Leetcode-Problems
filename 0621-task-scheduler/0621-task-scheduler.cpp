class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(auto& a:tasks){
            mp[a-'A']++;
        }
        int time=0;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int i:temp){
                if(i>0){
                    pq.push(i);
                }
            }
            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
    return time;
    }
};