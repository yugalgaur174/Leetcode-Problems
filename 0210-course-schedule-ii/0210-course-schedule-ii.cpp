class Solution {
public:
    bool dfs(int i, vector<int> &visited, vector<int>& pathvisited,vector<int>& ans, vector<vector<int>>& adj){
        visited[i]=1;
        pathvisited[i]=1;

        for(int j=0;j<adj[i].size();j++){
            int aa=adj[i][j];
            if(!visited[aa]){
                if(dfs(aa,visited,pathvisited, ans, adj)){
                    return true;
                }
            }
            else{
                if(pathvisited[aa]==1){
                    return true;
                }
            }
        }
        pathvisited[i]=0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<int> visited(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited, pathvisited, ans, adj)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};