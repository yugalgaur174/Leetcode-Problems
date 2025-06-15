class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int mx = num, mn = num;

        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                string t = s;
                for (char &c : t) {
                    if (c == x) c = y;
                }
                if (t[0] != '0') {
                    int val = stoi(t);
                    mx = max(mx, val);
                    mn = min(mn, val);
                }
            }
        }
        return mx - mn;
    }
};
