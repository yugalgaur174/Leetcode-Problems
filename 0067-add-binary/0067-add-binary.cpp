class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        if(a.size()>b.size()){
            while(a.size()!=b.size()){
                b="0"+b;
            }
        }
        else{
            while(a.size()!=b.size()){
                a="0"+a;
            }
        }
        int carry=0;
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]==b[i]){
                if(a[i]=='1'){
                    if(carry==0){
                        ans="0"+ans;
                        // carry=1;
                    }
                    else{
                        ans="1"+ans;
                        // carry=0;
                    }
                    carry=1;
                }
                else{
                    if(carry==0){
                        ans="0"+ans;
                        carry=0;
                    }
                    else{
                        ans="1"+ans;
                        carry=0;
                    }
                }
            }
            else{
                if(carry==1){
                    ans="0"+ans;
                    carry=1;
                }
                else{
                    ans="1"+ans;
                    carry=0;
                }
            }
        }
        if(carry==1){
                    ans="1"+ans;

        }
        return ans;
    }
};