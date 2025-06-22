class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int a=s.size()%k;
        a=k-a;
        a%=k;
        for(int i=0;i<a;i++){
            s+=fill;
        }
        vector<string> ans;
        for(int i=0;i<s.size();i=i+k){
            string z="";
            z=z+s.substr(i,k);
            ans.push_back(z);
        }
        return ans;
    }
};