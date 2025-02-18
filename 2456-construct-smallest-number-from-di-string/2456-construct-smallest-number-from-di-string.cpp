class Solution {
public:
    string ans = "";

    void findSmallest(string& s, string& pattern, bool used[10]) {
        if (!ans.empty()) return; 

        if (s.size() == pattern.size() + 1) { 
            ans = s;
            return;
        }

        for (int j = 1; j <= 9; j++) {
            if (used[j]) continue;

            if (!s.empty()) {
                int prev = s.back() - '0';
                if ((pattern[s.size() - 1] == 'I' && prev >= j) ||
                    (pattern[s.size() - 1] == 'D' && prev <= j))
                    continue;
            }

            used[j] = true;
            s.push_back(j + '0');
            findSmallest(s, pattern, used);
            s.pop_back();
            used[j] = false;
        }
    }

    string smallestNumber(string pattern) {
        bool used[10] = {false};
        string s = "";
        findSmallest(s, pattern, used);
        return ans;
    }
};
