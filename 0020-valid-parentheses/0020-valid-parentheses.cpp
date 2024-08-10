class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push('a');
            else if(s[i]=='[') st.push('b');
            else if(s[i]=='{') st.push('c');
            else if(s[i]==')'){
                if(st.size()==0) return false;

                else if(st.top()=='a'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(st.size()==0) return false;
                else if(st.top()=='b'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(st.size()==0) return false;

                else if(st.top()=='c'){
                    st.pop();
                }
                else{
                    return false;
                }
            }

        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }
};