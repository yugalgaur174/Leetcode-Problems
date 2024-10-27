class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size();
        if(n==0) return ans;
        int m=matrix[0].size();
        int k=min(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int maxsize=min(n-i,m-j);
                    for(int size=1;size<=maxsize;size++){
                        if(issquare(matrix, i,j,size)) ans++;
                        else break;
                    }
                }
            }
        }
        return ans;
    }
    private:
   bool issquare(  const vector<vector<int>>& matrix, int x,int y, int size){
        for(int i=x;i<x+size;i++){
            for(int j=y;j<y+size;j++){
                if(matrix[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};