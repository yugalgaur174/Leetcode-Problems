class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> col,row;
        map<int,pair<int, int>> mark;
        int n=mat[0].size();
        int m=mat.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mark[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            col[mark[arr[i]].first]++;
            row[mark[arr[i]].second]++;
            // cout<<arr[i]<<" "<<mark[arr[i]].first<<" "<<mark[arr[i]].second<<endl;
            if(col[mark[arr[i]].first]==n || row[mark[arr[i]].second]==m){
                return i;
            }
        }
        return 0;
    }
};