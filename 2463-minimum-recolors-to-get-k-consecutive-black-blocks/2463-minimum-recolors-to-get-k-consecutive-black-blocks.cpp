class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // if(blocks.size()<k)return
        int m=INT_MAX;
        string s="";
        int curr=0;
        for(int i=0;i<k;i++){
            s+=blocks[i];
            if(blocks[i]=='W'){
                curr++;
            }
        }
        m=min(m,curr);
        for(int i=k;i<blocks.size();i++){
            if(s[0]=='W'){
                curr--;
            }
            s.erase(s.begin());
            s+=blocks[i];
            if(blocks[i]=='W'){
                curr++;
            }
            m=min(m,curr);
        }
        return m;
    }
};