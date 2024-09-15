class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskPos;
        maskPos[0] = -1;
        int mask = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch == 'a') mask ^= 1 << 0;
            else if (ch == 'e') mask ^= 1 << 1;
            else if (ch == 'i') mask ^= 1 << 2;
            else if (ch == 'o') mask ^= 1 << 3;
            else if (ch == 'u') mask ^= 1 << 4;
            
            if (maskPos.find(mask) != maskPos.end()) {
                maxLen = max(maxLen, i - maskPos[mask]);
            } else {
                maskPos[mask] = i;
            }
        }
        
        return maxLen;
    }
};
