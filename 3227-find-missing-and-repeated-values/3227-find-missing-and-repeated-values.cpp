class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        map<int, int> mpp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mpp[grid[i][j]]==1){
                    ans.push_back(grid[i][j]);
                }
                else{
                    mpp[grid[i][j]]++;
                }
            }
        }
        for(int i=1;i<=n*n;i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};