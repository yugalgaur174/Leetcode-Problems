class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word;
        unordered_map<string,int> mpp;
        stringstream ss(s1);
        while(ss>> word){
            mpp[word]++;
        }
        vector<string> ans;
        stringstream sss(s2);
        while(sss>> word){
            mpp[word]++;
        }
        for(auto& word:mpp){
            if(word.second<2) ans.push_back(word.first);
        }
        return ans;
    }
};