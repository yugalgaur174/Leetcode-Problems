class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        
        vector<int> row={-1,-1,0,1,1,1,0,-1};
        vector<int> col={0,-1,-1,-1,0,1,1,1};
        queue<pair<int, pair<int, int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int level=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
                if(r==n-1 && c==n-1){
                    return level;
                }
            for(int i=0;i<8;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr<0 ||nc<0 || nr>=n || nc>=n || grid[nr][nc]==1){
                    continue;
                }
                else{
                    grid[nr][nc]=1;
                    q.push({level+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};