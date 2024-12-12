class Solution {
public:
    int maximumLength(string s) {
        if(s.size()<3)return -1;
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                if(s[j]!=s[i])break;
                a+=s[j];
                int num=0;
                for(int k=0;k<=n-a.size();k++){
                    string temp = s.substr(k, a.size()); 
                    if(temp==a)num++;

                }
                if(num>2){
                    // maxi=max(maxi,a.size());
                    if(maxi<a.size()){
                        maxi=a.size();
                    }
                }
            }
        }
        if(maxi==0){
            return -1;
        }
        return maxi;
    }
};