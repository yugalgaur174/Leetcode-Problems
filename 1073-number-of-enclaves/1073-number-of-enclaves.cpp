class Solution {
public:
    vector<int> row={0,-1,0,1};
    vector<int> col={1,0,-1,0};
    void dfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&visited){
        if(i<0 ||j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==0 || visited[i][j]){
            return;
        }
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+row[k];
            int c=j+col[k];
            dfs(r,c,grid,visited);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !visited[0][i]){
                dfs(0,i,grid,visited);
            }
            if(grid[n-1][i]==1 && !visited[n-1][i]){
                dfs(n-1,i,grid,visited);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};