class Solution {
public:
    string res = "";
    int count = 0;

    void finding(int n, string s, int k) {
        if (s.size() == n) {
            count++;
            if (count == k) res = s; 
            return;
        }

        for (char ch : {'a', 'b', 'c'}) { 
            if (s.empty() || s.back() != ch) { 
                finding(n, s + ch, k);
                if (!res.empty()) return;  
            }
        }
    }

    string getHappyString(int n, int k) {
        res = "";
        count = 0;
        finding(n, "", k);
        return res;
    }
};
