class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int a=events[0][1];
        int ans=events[0][0];
        for(int i=1;i<events.size();i++){
            int d=events[i][1]-events[i-1][1];
            if(d>a){
                a=d;
                ans=events[i][0];
            }
            else if(d==a){
                ans=min(ans,events[i][0]);
            }
        }
        return ans;
    }
};