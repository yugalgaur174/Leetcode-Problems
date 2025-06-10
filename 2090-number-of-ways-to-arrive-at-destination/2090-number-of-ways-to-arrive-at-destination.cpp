class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0];
            int b=roads[i][1];
            int c=roads[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a, c});
        }
        int mod = 1e9 + 7;
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        int ans=1;
        vector<long long> ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            
            for(int i=0;i<adj[node].size();i++){
                int nnode=adj[node][i].first;
                long long dd=adj[node][i].second;
                long long newdist=d+dd;
                if(newdist<=dist[nnode]){
                    if(newdist==dist[nnode]){
                        ways[nnode]=(ways[nnode]+ways[node])%mod;
                        continue;
                    }
                    ways[nnode]=ways[node];
                    pq.push({newdist,nnode});
                    dist[nnode]=newdist;
                    
                }
            }
        }
        return ways[n-1];
        // int arr=dist[n-1];
        // for(int i=0;i<n;i++){
        //     dist[i]=INT_MAX;
        // }
        // pq.push({0,0});
        // while(!pq.empty()){
        //     int node=pq.top().second;
        //     int d=pq.top().first;
        //     pq.pop();
        //     if(node==n-1 && d==arr){
        //         ans++;
        //     }
        //     for(int i=0;i<adj[node].size();i++){
        //         int nnode=adj[node][i].first;
        //         int dd=adj[node][i].second;
        //         int newdist=d+dd;
        //         if(newdist<=dist[nnode]){
        //             dist[nnode]=newdist;
        //             pq.push({newdist,nnode});
        //         }
        //     }
        // }
        // return ans;
    }
};