class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            auto k=words[i].find(pref);
            if(k==0)ans++;
        }
        return ans;
    }
};