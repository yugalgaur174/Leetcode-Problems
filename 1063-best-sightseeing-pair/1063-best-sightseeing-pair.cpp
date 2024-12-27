class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int m=0,ans=0;
        for(int i=0;i<values.size();i++){
        int j=i;
            ans=max(ans,m+values[j]-j);
            m=max(m, values[j]+j);
        }
        return ans;
    }
};