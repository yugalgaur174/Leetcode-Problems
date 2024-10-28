class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_set<long long> st(nums.begin(), nums.end());
        int ans=-1;
        for(int& num: nums){
            long long a=num;
            int m=0;
            while(st.count(a)){
                
                m++;
                a*=a;
            }
            if(m>1)ans=max(m,ans);
        }
        // if(ans==1) return -1;
        return ans;
    }
};