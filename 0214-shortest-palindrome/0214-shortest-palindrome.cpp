class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string srev(s.rbegin(), s.rend());
        string snew = s + "#" + srev;
        int nnew = snew.size();
        vector<int> lps(nnew, 0);
        for(int i = 1, len = 0; i < nnew; ){
            if(snew[i] == snew[len]){
                ++len;
                lps[i] = len;
                ++i;
            }else{
                if(len > 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    ++i;
                }
            }
        }

        return srev.substr(0, n - lps[nnew-1]) + s;
    }
};
// class Solution {
// public:
//     bool palindrome(string s,int ll){
//         int l=0;
//         int r=ll;
//         while(l<r){
//             if(s[l]!=s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
//     string shortestPalindrome(string s) {
//         if(palindrome(s,s.size()-1)) return s;
//         stack<char> st;
//         for(int i=s.size()-1;i>=0;i--){
//             if(palindrome(s,i)) break;
//             else{
//                 st.push(s[i]);
//             }
//         }
//         while(!st.empty()){
//             s=st.top()+s;
//             st.pop();
//         }
//         return s;

//     }
// };