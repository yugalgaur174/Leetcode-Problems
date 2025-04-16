class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;

                int mx = 0, mn = INT_MAX;
                for (auto& p : mpp) {
                    mx = max(mx, p.second);
                    mn = min(mn, p.second);
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};
