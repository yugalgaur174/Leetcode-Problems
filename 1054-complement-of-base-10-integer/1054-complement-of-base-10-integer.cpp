class Solution {
public:
string convert2binary(int n){
        if(n==0) return "0";
        string res="";
        while(n>0){
            if(n%2==1){
                res+="1";
            }
            else{
                res+="0";
            }
            n=n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
   long long  convert2decimal(string a){
        int len=a.length();
        long long p2=1;
        long long num=0;
        for(int i=len-1;i>=0;i--){
            if(a[i]=='1'){
                num+=p2;
            }
            p2=p2*2;
        }
        return num;
    }
    int bitwiseComplement(int num) {
        string a=convert2binary(num);
        string cmp="";
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                cmp+='1';
            }
            else{
                cmp+='0';
            }
        }
        return convert2decimal(cmp);
    }
};