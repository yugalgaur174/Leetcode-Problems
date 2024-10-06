class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;
        vector<string> s1, s2;
        
        while (ss1 >> word) {
            s1.push_back(word);
        }
        while (ss2 >> word) {
            s2.push_back(word);
        }
        
        if (s1.size() < s2.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        int i = 0;
        while (i < s2.size() && s1[i] == s2[i]) {
            i++;
        }

        int j = 0;
        while (j < s2.size() && s1[s1.size() - 1 - j] == s2[s2.size() - 1 - j]) {
            j++;
        }

        return i + j >= s2.size();
    }
};