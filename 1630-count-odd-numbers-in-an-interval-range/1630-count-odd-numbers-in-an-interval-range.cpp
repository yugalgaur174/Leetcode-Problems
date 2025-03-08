class Solution {
public:
    int countOdds(int low, int high) {
        if(high%2==0){
            return high/2-low/2;
        }
        
        else {
            return high/2-low/2+1;
        }
        
    }
};