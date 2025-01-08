class Solution {
public:
    bool checking(string a, string b){
        if(a.size()>b.size())return false;
        auto first=b.find(a);
        if(first!=0)return false;
        string c = b.substr(b.size() - a.size(), a.size());
        if(a!=c)return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(checking(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};