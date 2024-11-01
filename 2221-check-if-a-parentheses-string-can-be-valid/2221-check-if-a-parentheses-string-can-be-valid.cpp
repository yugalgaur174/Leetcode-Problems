class Solution {
public:
    bool canBeValid(string s, string locked) {
        int p = 0, n = 0;
        int length = s.size();
        if (length % 2 == 1) return false;
        for(int i=0;i<length;i++){
            if(s[i]=='(' || locked[i]=='0'){
                p++;
            }       
            else{
                p--;
            } 
            if(p<0) return false;
        }
        for(int i=length-1;i>=0;i--){
            if(s[i]==')'|| locked[i]=='0'){
                n++;
            }
            else{
                n--;
            }
            if(n<0){
                return false;
            }
        }
        return true;
    }
};