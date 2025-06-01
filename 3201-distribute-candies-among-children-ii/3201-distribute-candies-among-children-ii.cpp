class Solution {
public:
    #define ll long long
    long long distributeCandies(int n, int limit) {
        ll ans=0;
        for(int i=0;i<=min(n,limit);i++){
            ll rem=n-i;
            if(rem>2*limit)continue;
            ll low=max(0ll,rem-limit);
            ll high=min(rem,(ll)limit);
            if(low<=high){
                ans+=(high-low+1);
            }
        }
        return ans;
    }
};