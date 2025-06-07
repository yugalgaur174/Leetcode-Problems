
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        int n=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            n++;
            q.pop();
            for(int i=0;i<adj[a].size();i++){
                int b=adj[a][i];
                indegree[b]--;
                if(indegree[b]==0){
                    q.push(b);
                }
            }
        }
        return (n==numCourses);
    }
};