class Solution {
public:
    bool check(string a, string b, int j) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i + j])
                return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        long long a = 0;
        for (int i = 0; i < needle.size(); i++) {
            a += int(needle[i]) * pow(2, i);
        }
        if (n < needle.size())
            return -1;
        int b = needle.size();
        long long sum = 0;
        for (int i = 0; i < b; i++) {
            sum += int(haystack[i]) * pow(2, i);
        }
        if (sum == a && check(needle, haystack, 0)) {
            return 0;
        }
        for (int i = b; i < n; i++) {
            sum -= int(haystack[i - b]);
            sum /= 2;
            sum += int(haystack[i]) * pow(2, b-1);
            if (sum == a && check(needle, haystack, i - b + 1)) {
                return i - b + 1;
            }
        }
        return -1;
    }
};