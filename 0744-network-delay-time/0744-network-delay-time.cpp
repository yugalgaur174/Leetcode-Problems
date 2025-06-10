class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int c=times[i][2];
            adj[a].push_back({b,c});
        }
        priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
        pq.push({0,k});
        vector<int> ans(n+1,INT_MAX);
        ans[k]=0;
        while(!pq.empty()){
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[b].size();i++){
                int c=adj[b][i].first;
                int d=adj[b][i].second;
                int dist=a+d;
                if(dist<ans[c]){
                    ans[c]=a+d;
                    pq.push({dist,c});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==INT_MAX){
                return -1;
            }
        }
        int m=INT_MIN;
        for(int i=1;i<=n;i++){
            m=max(m,ans[i]);
        }
        return m;
    }
};