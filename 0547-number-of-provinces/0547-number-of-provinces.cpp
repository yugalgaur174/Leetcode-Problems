class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<is.size();i++){
            for(int j=0;j<is[i].size();j++){
                if(is[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int start=0;
        int cnt=0;
        for(int i=0;i<is.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};