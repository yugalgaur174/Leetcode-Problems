class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> visited(n, vector<int> (m,INT_MAX));
        visited[0][0]=0;
        vector<int> row={-1,0,1,0};
        vector<int> col={0,-1,0,1};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int a=pq.top().first;
            int b=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(b==n-1 && c==m-1){
                return a;
            }
            for(int i=0;i<4;i++){
                int r=b+row[i];
                int cc=c+col[i];
                if(r<0 || cc<0 || r>=n || cc>=m){
                    continue;
                }
                else{
                    int diff=abs(heights[r][cc]-heights[b][c]);
                    int eff=max(visited[b][c],diff);
                    if(eff<visited[r][cc]){
                        visited[r][cc]=eff;
                        pq.push({eff,{r,cc}});
                    }
                    
                }
            }
        }
        return 0;
    }
};