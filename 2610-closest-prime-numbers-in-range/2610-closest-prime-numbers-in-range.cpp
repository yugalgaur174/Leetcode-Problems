class Solution {
public:
    bool checkprime(int num) {
        if (num == 1)
            return false;
        int i = 2;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr;
        for (int i = left; i <= right; i++) {
            if (checkprime(i)){
                arr.push_back(i);
            }
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        vector<int> ans;
        if(arr.size()<2){
            ans.push_back(-1);
        ans.push_back(-1);
        return ans;
            // return 
        }
        int m=INT_MAX;
        for(int i=arr.size()-1;i>0;i--){
            int s=arr[i]-arr[i-1];
            m=min(m,s);
        }
        cout<<endl<<"m="<<m<<endl;
        for(int i=0;i<arr.size()-1;i++){
            int s=abs(arr[i]-arr[i+1]);
            cout<<endl<<"s="<<s;
            if(s==m){
                ans.push_back(arr[i]);
                ans.push_back(arr[i+1]);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};