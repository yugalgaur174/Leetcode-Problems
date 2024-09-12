class Solution {
public:
    string convert(int a){
        if(a==0) return "0";
        string z="";
        while(a>0){
            z+=a%2+'0';
            a/=2;
        }
        reverse(z.begin(),z.end());
        return z;
    }
    string convertDateToBinary(string date) {
        // int a,b,c;
        int a = stoi(date.substr(0, 4));  
        int b = stoi(date.substr(5, 2)); 
        int c = stoi(date.substr(8, 2));
        string z=convert(a)+"-"+convert(b)+"-"+convert(c);
        return z;
    }
};