class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> arr(n,0);
        int sum=mean*(rolls.size()+n);
        int s=0;
        for(int i=0;i<rolls.size();i++){
            s+=rolls[i];
        }
        sum-=s;
        int i=0;
        if(sum<n || sum>6*n){
            return {};
        }
        while(sum>0){
            arr[i%n]++;
            i++;
            sum--;
        }
        return arr;
    }
};