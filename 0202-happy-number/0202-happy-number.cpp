class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mpp;
        while(n!=1){
            if(mpp[n]>1) return false;
            mpp[n]++;
            int sum=0;
            while(n>0){
                sum+=pow((n%10),2);
                n/=10;
            }
            
            n=sum;
        }
        return true;
    }
};