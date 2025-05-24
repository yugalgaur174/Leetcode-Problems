class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                a++;
                if(a==1){
                    continue;
                }
                else{
                    ans+=s[i];
                }
            }
            else{
                a--;
                if(a==0){
                    continue;
                }
                else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};