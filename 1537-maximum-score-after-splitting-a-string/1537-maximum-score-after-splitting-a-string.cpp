class Solution {
public:
    int maxScore(string s) {
        int zero=0;
        int one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        if(zero==s.size() || one==s.size())return s.size()-1;
        int z=0;
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                z++;
            }
            if(s[i]=='1'){
                one--;
            }
            cout<<z<<" "<<one<<endl;
            ans=max(ans,z+one);
        }
        return ans;
    }
};