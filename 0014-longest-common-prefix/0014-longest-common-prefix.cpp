class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int m=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int n=strs[i].size();
            m=min(m,n);
        }
        for(int i=0;i<m;i++){
            char a=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=a){
                    return ans;
                }
            }
            ans+=a;
        }
        return ans;
    }
};