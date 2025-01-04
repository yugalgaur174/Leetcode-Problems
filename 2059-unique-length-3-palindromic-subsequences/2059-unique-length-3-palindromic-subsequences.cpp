class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        for(char c='a';c<='z';c++){
            int l=s.find_first_of(c);
            int r=s.find_last_of(c);
            unordered_set<char> st;
            for(int i=l+1;i<r;i++){
                st.insert(s[i]);
            }
            ans+=st.size();

        }
        return ans;
    }
};