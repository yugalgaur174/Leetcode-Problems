class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, string> mpp;
        vector<int>visited(graph.size(),0);
        for(int j=0;j<graph.size();j++){
            if(!visited[j]){

        queue<pair<int,string>> q;
        q.push({j,"red"});
        mpp[j]="red";
            visited[j]=1;
        while(!q.empty()){
            int a=q.front().first;
            string b=q.front().second;
            q.pop();
            for(int i=0;i<graph[a].size();i++){
                int c=graph[a][i];
                if(!visited[c]){
                    visited[c]=1;
                    if(b=="red"){
                        mpp[c]="blue";
                        q.push({c,"blue"});
                    }
                    else{
                        mpp[c]="red";
                        q.push({c,"red"});
                    }
                }
                else{
                    if(mpp[c]==b){
                        return false;
                    }
                }
            }

            }
        }
        }
        
        return true;
    }
};