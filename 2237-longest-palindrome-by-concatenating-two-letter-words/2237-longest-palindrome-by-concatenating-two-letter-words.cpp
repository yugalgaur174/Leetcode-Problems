class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string, int> mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
        int a=0;
        
        for(auto &it:mpp){
            string s=it.first;
            reverse(s.begin(),s.end());
            if(s==it.first){
                ans+=(it.second/2)*4;
                if(it.second%2==1){
                    a=1;
                }
            }
            else if (mpp.find(s) != mpp.end()){
                int m=min(it.second, mpp[s]);
                ans+=4*m;
                it.second-=m;
                mpp[s]-=m;
            }
        }
        return ans+a*2;
    }
};