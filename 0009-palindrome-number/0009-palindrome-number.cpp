class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int b=x;
        long long a=0;
        while(x>0){
            a=a*10+x%10;
            if(a>INT_MAX) return false;
            x=x/10;
        }
        if(a==b) return true;
        return false;
    }
};