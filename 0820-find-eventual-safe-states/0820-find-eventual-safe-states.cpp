class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<bool> check(graph.size(),false);
        int change=0;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){
                check[i]=true;
                change++;
            }
        }
        while(change>0){
            change=0;
            for(int i=0;i<graph.size();i++){
                if(check[i])continue;
                bool yes=false;
                for(int j=0;j<graph[i].size();j++){
                    if(check[graph[i][j]]!=true){
                        yes=true;
                        break;
                    }
                }
                if(!yes){
                    check[i]=true;
                    change++;
                }
            }
        }
        for(int i=0;i<check.size();i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};