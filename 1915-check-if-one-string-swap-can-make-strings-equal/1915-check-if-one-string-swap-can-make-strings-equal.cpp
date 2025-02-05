class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        int n1 = s1.size();
        int n2 = s2.size();
        int a = -1, b = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (a == -1) {
                    a = i;
                } else {
                    b = i;
                    char z = s1[a];
                    s1[a] = s1[b];
                    s1[b] = z;
                    break;
                }
            }
        }
        if (a == -1 || b == -1)
            return false;

        return s1 == s2;
    }
};