class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        unordered_map<char, int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int cnt=0;
        for(auto it: mpp){
            if(it.second%2!=0){
                cnt++;
            }
        }
        if(cnt>k)return false;
        return true;
    }
};