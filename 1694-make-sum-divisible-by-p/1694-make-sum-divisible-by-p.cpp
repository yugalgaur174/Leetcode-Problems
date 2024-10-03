class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        int k = accumulate(nums.begin(), nums.end(), 0LL) % p;
        
        if(k == 0) return 0;
        
        unordered_map<int, int> lastidx;
        int ans = n;
        int runsum = 0;
        
        lastidx[0] = -1;
        for(int i = 0; i < n; ++i){
            runsum = (runsum+nums[i])%p;
            if(lastidx.count((runsum-k+p)%p)){
                ans = min(ans, i - lastidx[(runsum-k+p)%p]);
            }
            lastidx[runsum] = i;
        }
        
        return (ans == n) ? -1 : ans;
    }
};