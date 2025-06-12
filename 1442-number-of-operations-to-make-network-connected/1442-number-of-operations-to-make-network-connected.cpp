class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int comp=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                comp++;
                queue<int> q;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int a=q.front();
                    q.pop();
                    for(int j=0;j<adj[a].size();j++){
                        int b=adj[a][j];
                        if(!visited[b]){
                            q.push(b);
                            visited[b]=1;
                        }
                    }
                }
            }

        }
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        int count=0;
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            if(visited[a] && visited[b]){
                count++;
            }
            else{
                visited[a]=1;
                visited[b]=1;
            }
        }
        // cout<<comp<<" "<<count;
        if(comp-1<=count){
            return comp-1;
        }
        return -1;
        
    }
};