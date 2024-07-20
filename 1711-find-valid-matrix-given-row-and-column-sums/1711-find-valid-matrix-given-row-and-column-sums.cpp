class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> a(m, vector<int>(n, 0));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                a[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=a[i][j];
                colSum[j]-=a[i][j];
            }
        }
        return a;
    }
};