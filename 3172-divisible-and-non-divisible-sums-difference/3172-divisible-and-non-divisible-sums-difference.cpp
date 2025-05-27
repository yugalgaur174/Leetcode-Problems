class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=n/m;
        int k=num1;
        num1=0;
        for(int i=0;i<k;i++){
            num1+=(i+1)*m;
        }
        int num2=(n*(n+1))/2;
        num2-=num1;
        return num2-num1; 

    }
};