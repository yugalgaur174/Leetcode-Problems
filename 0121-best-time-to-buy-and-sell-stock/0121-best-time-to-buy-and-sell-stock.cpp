class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
            int max=0,s=0,d=0;
            int left=10000;
            for(int i=0;i<n;i++){
                if(prices[i]<left){
                    left=prices[i];
                }
                s=prices[i]-left;
                if(s>max){
                    max=s;
                    
                    
                }
                
            }
        return max;
           
        // for(int i=0;i<n;i++){
        // int sum=0;
        //     for(int j=n-1;j>i;j--){
        //         sum=prices[j]-prices[i];
        //         if(sum>max){
        //             max=sum;
        //         }
        //     }
        // }
    }
};