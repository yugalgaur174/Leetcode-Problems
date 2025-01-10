class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> maxFreq;
        
        for (const string& word : words2) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
                maxFreq[c] = max(maxFreq[c], freq[c]);
            }
        }
        
        for (const string& word : words1) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }
            bool isUniversal = true;
            for (const auto& [c, count] : maxFreq) {
                if (freq[c] < count) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
