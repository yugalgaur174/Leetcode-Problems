class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0){
            return high/2-low/2;
        }
        else if(low%2==1 && high%2==0){
            return high/2-low/2;
        }
        else {
            return high/2-low/2+1;
        }
        
    }
};