class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int original = grid[sr][sc];
        if (original == color) return grid;
        q.push(make_pair(sr,sc));
        vector<int> row = {0, -1, 0, 1 };
        vector<int> col = { 1, 0, -1, 0 };
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                int a=it.first;
                int b=it.second;
                for(int j=0;j<4;j++){
                    int r=a+row[j];
                    int c=b+col[j];
                    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()){
                        continue;
                    }
                    else{
                        if(grid[r][c]==original){
                            grid[r][c]=color;
                            q.push(make_pair(r,c));
                        }
                    }
                }
            }
        }
        grid[sr][sc]=color;
        return grid;
    }
};