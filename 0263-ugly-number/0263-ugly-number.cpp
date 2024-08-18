class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1;
        // vector<int> a;
        // for (int i = 7; i < n + 1; i++) {
        //     if (n % i == 0) {
        //         a.push_back(i);
        //     }
        // }
        // for (const auto& n : a) {
        // int flag=0;
        //     for (int i = 2; i <= sqrt(n); i++) {
        //         if (n % i == 0 ) {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag==0 && n>5){
        //         return false;
        //     }
        // }
        // return true;
    }
};