class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)return s;
        char a=s[0];
        char b=s[1];
        string ans="";
        ans+=a;
        ans+=b;
        for(int i=2;i<s.size();i++){
            if(a==b){
                if(a==s[i]){
                    continue;
                }
                else{
                    ans+=s[i];
                    a=s[i-1];
                    b=s[i];
                }
            }
            else{
                ans+=s[i];
                a=s[i-1];
                b=s[i];
            }
        }
        return ans;
    }
};