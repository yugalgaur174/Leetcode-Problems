class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int ans = 0;
        while (ss >> word) {
            bool valid = true;
            int cnt = 0;
            for (int i = 0; i < word.size(); i++) {
                if (isdigit(word[i])) {
                    valid = false;
                    break;
                } else if (word[i] == '-' && valid) {
                    cnt++;
                    if (i - 1 >= 0 && i + 1 < word.size() && cnt <= 1) {
                        if (word[i - 1] >= 'a' && word[i - 1] <= 'z' &&
                            word[i + 1] >= 'a' && word[i + 1] <= 'z') {
                            continue;
                        } else {
                            valid = false;
                    break;

                        }
                    } else {
                        valid = false;
                    break;

                    }
                } else if (word[i] == '!' || word[i] == ',' || word[i] == '.') {
                    if (i == word.size() - 1) {
                    } else {
                        valid = false;
                    break;

                    }
                }
            }
            if (valid) {
                cout << word << endl;
                ans++;
            }
        }
        return ans;
    }
};