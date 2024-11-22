class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> copy(m);
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                copy[j]=matrix[i][j]^1;
            }
            for(int j=0;j<n;j++){
                if(matrix[j]==copy || matrix[i]==matrix[j]){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};