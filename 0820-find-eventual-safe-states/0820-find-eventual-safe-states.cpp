class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int i=0;i<adj[a].size();i++){
                int b=adj[a][i];
                indegree[b]--;
                if(indegree[b]==0){
                    q.push(b);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};