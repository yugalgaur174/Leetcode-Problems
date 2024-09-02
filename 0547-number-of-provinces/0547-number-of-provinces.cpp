class Solution {
public:
    void dfss(unordered_map<int,vector<int>> mpp,int i, vector<int>&visited){
        visited[i]=1;
        for(auto it:mpp[i]){
            if(!visited[it]){

            dfss(mpp,it,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        unordered_map<int,vector<int>> mpp;
        int n=isConnected.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){mpp[i].push_back(j); mpp[j].push_back(i);}
            }
        }
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                cnt++;
                dfss(mpp,i,visited);

            }
        }
        return cnt;
    }
};