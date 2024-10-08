class Solution {
public:
    int ans=0;
    void check(string s){
        stack<char> st;
        int n=s.size();
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() &&st.top()=='[' && s[i]==']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return;
        else{
            ans= (st.size()/2+1)/2;
        }
    }
    int minSwaps(string s) {
        if(s.size()==0) return 0;
        check(s);
        return ans;
    }
};