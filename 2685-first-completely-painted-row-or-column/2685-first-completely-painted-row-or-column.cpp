class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> col,row;
        map<int,pair<int, int>> mark;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mark[mat[i][j]]={i,j};
            }
        }
        
        for(int i=0;i<arr.size();i++){
            col[mark[arr[i]].first]++;
            row[mark[arr[i]].second]++;
            // cout<<arr[i]<<" "<<mark[arr[i]].first<<" "<<mark[arr[i]].second<<endl;
            if(col[mark[arr[i]].first]==mat[0].size() || row[mark[arr[i]].second]==mat.size()){
                return i;
            }
        }
        return 0;
    }
};