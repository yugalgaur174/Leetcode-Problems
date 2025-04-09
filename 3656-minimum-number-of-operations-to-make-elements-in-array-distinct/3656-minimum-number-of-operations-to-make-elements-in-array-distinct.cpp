class Solution {
public:
    bool distinct(vector<int> nums){
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        if(st.size()==nums.size())return true;
        return false;
    }
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        while(nums.size()>0){
            if(!distinct(nums)){
                int i=3;
                ans++;
                while(nums.size()>0 && i>0){
                    nums.erase(nums.begin());
                    i--;
                }
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};