class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int a=flights[i][0];
            int b=flights[i][1];
            int c=flights[i][2];
            adj[a].push_back({b,c});
        }
        vector<int> visited(n,INT_MAX);
        visited[src]=0;
        queue<pair<int, pair<int, int>>>pq;
        pq.push({0,{src,0}});
        int ans=INT_MAX;
        while(!pq.empty()){
            int a=pq.front().first;
            int b=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();
            if(b==dst){
                ans=min(ans,c);
            }
            for(int i=0;i<adj[b].size();i++){
                int d=adj[b][i].first;
                int dist=adj[b][i].second+c;
                if(dist<visited[d] && a+1<=k+1){
                    visited[d]=dist;
                    pq.push({a+1,{d,dist}});
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};