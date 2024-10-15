class Solution {
public:
    long long minimumSteps(string s) {
        long long x=0;
        long long ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                x++;
            }
            else{
                ans+=x;
            }
        }
        return ans;
    }
};