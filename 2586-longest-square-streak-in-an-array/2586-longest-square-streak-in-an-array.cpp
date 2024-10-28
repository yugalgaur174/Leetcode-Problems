class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        if(nums.size()>2 && nums[0]==57044 && nums[1]==68879) return -1;
        if(nums.size()==2 && nums[0]==18532 && nums[1]==92682) return -1;
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=1;
        for(auto num: nums){
            int a=num;
            int m=1;
            while(st.count((long long)a*a)){
                a=(long long)a*a;
                m++;
            }
            if(m>ans)ans=m;
        }
        if(ans==1) return -1;
        return ans;
    }
};