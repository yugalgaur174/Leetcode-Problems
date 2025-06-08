class Solution {
public:
    static bool  comp(vector<int>a, vector<int> b){
        for(int i=0;i<26;i++){
             if (a[i] > b[i]) return true;
            if (a[i] < b[i]) return false;
        }
        return a[26] < b[26];
    }
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> win(26,vector<int>(27,0));
        unordered_map<int, int> mpp;
        for(int i=0;i<votes.size();i++){
            for(int j=0;j<votes[i].size();j++){
                int a=votes[i][j]-'A';
                win[a][j]++;
                mpp[a]++;
            }
        }
        for(int i=0;i<26;i++){
            win[i][26]=i;
        }
        sort(win.begin(),win.end(),comp);
        string ans="";
        for(int i=0;i<26;i++){
            int a=win[i][26];
            if(mpp[a]){
                ans+=(char)('A'+a);
            }
        }
        return ans;
    }
};