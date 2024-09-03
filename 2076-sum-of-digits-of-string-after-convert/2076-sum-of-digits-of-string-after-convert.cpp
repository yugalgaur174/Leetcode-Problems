class Solution {
public:
    int getLucky(string s, int k) {
        string a="";
        for(int i=0;i<s.size();i++){
            int z=s[i]-'a'+1;
            a+=to_string(z);
        }
        // long long m=stoi(a);
        int m;
        while(k>0){
            int n=0;
            for(int i=0;i<a.size();i++){
                n=n+a[i]-'0';
            }
            a=to_string(n);
            m=n;
            k--;
        }
        return m;
    }
};