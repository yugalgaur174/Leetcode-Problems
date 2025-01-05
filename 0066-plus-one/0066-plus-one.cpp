class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int a;
        int b=1;
        for(int i=n;i>=0;i--){
            a=digits[i]+b;

            if(a>9){
                b=1;
                digits[i]=0;
            }
            else{
                digits[i]=a;
                b=0;
            }

        }
        if(b==1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};