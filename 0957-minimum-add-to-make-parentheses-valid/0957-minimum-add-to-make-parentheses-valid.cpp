class Solution {
public:
    int minAddToMakeValid(string s) {
        // int a=0;
        stack <int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                st.push(1);
            }
            else if(s[i]==')'){
                if(!st.empty() &&st.top()==1){
                    st.pop();
                }
                else{
                    st.push(2);
                }
            }
        }
        return st.size();
    }
};