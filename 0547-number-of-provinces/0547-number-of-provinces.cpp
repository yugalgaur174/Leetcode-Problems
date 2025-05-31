class Solution {
public:
    int findCircleNum(vector<vector<int>>& connected) {
        vector<vector<int>> adj(connected.size()+1);
        for(int i=0;i<connected.size();i++){
            for(int j=0;j<connected.size();j++){
                if(i!=j && connected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int> visited(connected.size()+1,0);
        int ans=0;
        for(int i=1;i<=connected.size();i++){
            if(visited[i]){
                continue;
            }
            ans++;
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int j=0;j<adj[a].size();j++){
                    if(!visited[adj[a][j]]){
                        visited[adj[a][j]]=1;
                        q.push(adj[a][j]);
                    }
                }
            }
        }
        return ans;
    }
};