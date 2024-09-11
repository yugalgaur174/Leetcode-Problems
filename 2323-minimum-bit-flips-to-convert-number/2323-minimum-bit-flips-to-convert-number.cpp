class Solution {
public:
    string bit(int a){
        string z="";
        if(a==0) return "0";
        while(a>0){
            z+=to_string(a%2);
            a=a/2;
        }
        reverse(z.begin(), z.end());
        return z;
    }
    int minBitFlips(int start, int goal) {
        string a=bit(start);
        string b=bit(goal);
        if (a.size() < b.size()) {
            a.insert(a.begin(), b.size() - a.size(), '0');
        } else {
            b.insert(b.begin(), a.size() - b.size(), '0');
        }
        int z=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])z++;
        }
        return z;
    }
};