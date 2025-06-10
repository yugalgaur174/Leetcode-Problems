class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int a=INT_MIN,b=INT_MAX;
        for(auto &it:mpp){
            if(it.second%2==1){
                a=max(a,it.second);
            }
            else{
                b=min(b,it.second);
            }
        }
        return a-b;
    }
};