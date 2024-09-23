class Solution {
public:
    int myAtoi(string s) {
        long long a = 0;
        int sign = 1;  // Default is positive
        bool started = false, hasSign = false;

        for (int i = 0; i < s.size(); i++) {
            // Skip spaces before number starts
            if (s[i] == ' ' && !started && !hasSign) {
                continue;
            }

            // Handle sign if it appears and no number has started yet
            if ((s[i] == '-' || s[i] == '+') && !started && !hasSign) {
                sign = (s[i] == '-') ? -1 : 1;
                hasSign = true;
            }
            // Handle digits
            else if (s[i] >= '0' && s[i] <= '9') {
                a = a * 10 + (s[i] - '0');
                started = true;
                
                // Stop if the number goes out of bounds
                if (a * sign > 2147483647) return 2147483647;
                if (a * sign < -2147483648) return -2147483648;
            }
            // Stop if any non-digit character appears after the number starts
            else if (started) {
                break;
            }
            // Return 0 if an invalid character appears before any digits
            else {
                return 0;
            }
        }
        return a * sign;
    }
};
