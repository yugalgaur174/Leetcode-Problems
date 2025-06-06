class Solution {
public:
    string robotWithString(string s) {
        multiset<char> st(s.begin(), s.end());
        stack<char> a;
        string ans = "";
        for (char c : s) {
            a.push(c);
            st.erase(st.find(c));

            while (!a.empty() && (st.empty() || a.top() <= *st.begin())) {
                ans += a.top();
                a.pop();
            }
        }
        while (!a.empty()) {
            ans += a.top();
            a.pop();
        }
        return ans;
    }
};
