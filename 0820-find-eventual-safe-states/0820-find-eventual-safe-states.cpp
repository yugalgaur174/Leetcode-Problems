class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> check(adj.size(),0);
        int change=0;
        for(int i=0;i<adj.size();i++){
            if(adj[i].size()==0){
                // ans.push_back(i);
                check[i]=1;
                change++;
            }
        }
        while(change>0){
            change=0;
            for(int i=0;i<adj.size();i++){
                if(check[i]) continue;
                int mark=0;
                for(int j=0;j<adj[i].size();j++){
                    if(check[adj[i][j]]==0){
                        mark=1;
                        break;
                    }
                }
                if(mark==0){
                    check[i]=1;
                    // ans.push_back(i);
                    change++;
                }
            }
        }
        for(int i=0;i<adj.size();i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};