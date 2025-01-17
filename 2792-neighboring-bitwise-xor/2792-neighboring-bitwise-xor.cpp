class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> ans;
        int n=derived.size();
        ans.push_back(0);
        for (int i = 0; i < n-1; i++) {
            if (derived[i] == 0) {
                ans.push_back(ans[i]);
            } else {
                if (ans[i] == 0) {
                    ans.push_back(1);
                } else {
                    ans.push_back(0);
                }
            }
        }
        if(ans[n-1]^ans[0]==derived[n-1])return true;
        ans.clear();
        ans.push_back(1);
        for (int i = 0; i < n-1; i++) {
            if (derived[i] == 0) {
                ans.push_back(ans[i]);
            } else {
                if (ans[i] == 0) {
                    ans.push_back(1);
                } else {
                    ans.push_back(0);
                }
            }
        }
        if(ans[n-1]^ans[0]==derived[n-1])return true;
        return false;
    }
};
