class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        map<int, int> mpp;
        int m=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>m){
                    m=grid[i][j];
                }
                if(mpp[grid[i][j]]==1){
                    ans.push_back(grid[i][j]);
                }
                else{
                    mpp[grid[i][j]]++;
                }
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};