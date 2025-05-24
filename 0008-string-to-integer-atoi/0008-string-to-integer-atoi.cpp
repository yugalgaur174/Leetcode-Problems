class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool nega=false;
        bool space=false;
        bool start=false;
        int i=0;
        while(s[i]==' '){
                i++;
        }
        for(i;i<s.size();i++){
            if(s[i]=='-' && !start){
                start=true;
                nega=true;
            }
            else if(s[i]=='+' && !start){
                start=true;
            }
            else if(!isdigit(s[i])){
                break;
            }
            else{
                start=true;
                ans=ans*10+s[i]-'0';
                 if (!nega && ans > INT_MAX) return INT_MAX;
                if (nega && -ans < INT_MIN) return INT_MIN;
            
            }
        }
        return nega ? -ans : ans;
    }
};