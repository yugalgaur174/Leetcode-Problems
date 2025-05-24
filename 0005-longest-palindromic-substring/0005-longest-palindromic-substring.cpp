class Solution {
public:
    string longestPalindrome(string s) {
        int ll=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                int len=r-l+1;
                if(len>ll){
                    ll=len;
                    ans=s.substr(l,len);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                int len=r-l+1;
                if(len>ll){
                    ll=len;
                    ans=s.substr(l,len);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};