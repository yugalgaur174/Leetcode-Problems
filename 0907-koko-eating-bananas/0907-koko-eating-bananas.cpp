class Solution {
public:
    long long time(vector<int> piles,long long x){
        long long ans=0;
        for(long long i=0;i<piles.size();i++){
            ans+=(piles[i] + x - 1) / x;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(time(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};