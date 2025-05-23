class Solution {
public:
    int check(vector<int> weights, int mid) {
    int day = 1;  
    int curr = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (curr + weights[i] > mid) {
            day++;
            curr = 0;
        }
        curr += weights[i];
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());;
        int high=accumulate(weights.begin(), weights.end(), 0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int c=check(weights, mid);
            if(c<=days){
                high=mid-1;
                ans=mid;
                cout<<c<<" "<<ans<<endl;
            }
            else if(c>days){
                low=mid+1;
            }
            
        }
        return ans;
    }
};