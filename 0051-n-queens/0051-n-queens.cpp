class Solution {
public:
    bool check(int i,int j, vector<int> &row, vector<int> &col,vector<int> &diag1, vector<int> & diag2){
        if(row[i]){
            return false;
        }
        if(col[j]){
            return false;
        }
        if(diag1[i-j+row.size()-1] || diag2[i+j]){
            return false;
        }
        return true;
    }
    void making(int i, vector<string> arr, vector<vector<string>>& ans, vector<int> row, vector<int> col,vector<int> diag1, vector<int> diag2){
        if(i==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int j=0;j<arr.size();j++){
            if(check(i,j,row, col,diag1, diag2)){
                arr[i][j]='Q';
                row[i]=1;
                col[j]=1;
                diag1[i-j+row.size()-1]=1;
                diag2[i+j]=1;
                making(i+1, arr, ans, row, col,diag1, diag2);
                arr[i][j]='.';
                row[i]=0;
                col[j]=0;
                diag1[i-j+row.size()-1]=0;
                diag2[i+j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> arr(n,string(n, '.'));
        vector<int> row(n,0);
        vector<int> col(n,0);
        vector<int> diag1(2*n-1,0);
        vector<int> diag2(2*n-1,0);
        making(0,arr,ans,row, col,diag1, diag2);
        return ans;
    }
};