class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        
        q.push({sr,sc});
       int mark=image[sr][sc];
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            image[r][c]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n&& ncol<m&& image[nrow][ncol]==mark){
                    q.push({nrow,ncol});
                    // vis[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};