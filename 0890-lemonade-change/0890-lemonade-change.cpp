class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // unordered_map<int,int> mpp;
        int a=0;
        int b=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                a++;
            }
            else if(bills[i]==10){
                if(a>0){
                    a--;
                    b++;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(a>0 && b>0){
                    b--;
                    a--;
                }
                else if(a>2){
                    a--;
                    a--;
                    a--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};