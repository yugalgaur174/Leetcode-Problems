class Solution {
public:
    bool ans=true;
    bool checkPowersOfThree(int n) {
        if(n==0)return true;
        if(n==2)return false;
        if(n%3==2)return false;
        ans=checkPowersOfThree(n/3);
        return ans;
    }
};