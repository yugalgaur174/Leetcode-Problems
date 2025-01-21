class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1=0,sum2=0;
        int n=grid[0].size();
        for(int i=0;i<n;i++){
            sum1+=grid[0][i];
            sum2+=grid[1][i];
        }
        long long right=sum1;
        long long left=0;long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            right-=grid[0][i];
            // sum1-=grid[0][i];
            ans=min(ans,max(right,left));
            left+=grid[1][i];
            // sum2
        }
        return ans;
    }
};