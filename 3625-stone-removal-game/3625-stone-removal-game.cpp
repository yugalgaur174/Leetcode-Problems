class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=true;
        int a=10;
        while(n>=0){
            if(alice){
                n=n-a;
                a--;
                alice=false;
            }
            else{
                n-=a;
                a--;
                alice=true;
            }
        }
        return alice;
    }
};