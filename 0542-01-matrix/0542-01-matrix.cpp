class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int> > visited(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int> > distance(mat.size(), vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        vector<int> row={-1,0,1,0};
        vector<int> col={0,1,0,-1};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int b=a.first.first;
            int cc=a.first.second;
            int d=a.second;
            for(int i=0;i<4;i++){
                int r=b+row[i];
                int c=cc+col[i];
                if(r<0 || c<0 || r>=mat.size() || c>=mat[0].size()){
                    continue;
                }
                else{
                    if(visited[r][c]){
                        continue;
                    }
                    else{
                        visited[r][c]=1;
                        distance[r][c]=d+1;
                        q.push({{r,c},d+1});
                    }
                }
            }
        }
        return distance;
    }
};