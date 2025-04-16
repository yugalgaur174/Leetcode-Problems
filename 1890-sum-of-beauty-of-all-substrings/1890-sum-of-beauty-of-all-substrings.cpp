class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char, int> mpp;
            for(int j=i;j<s.size();j++){
            int maxx=0;
            int minn=INT_MAX;
                mpp[s[j]]++;
                for(auto &it:mpp){
                    maxx=max(maxx,it.second);
                    minn=min(minn,it.second);
                }
                
                ans+=(maxx-minn);
            }
        }
        return ans;
    }
};