#include <algorithm>
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> arr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int start=max(i-k,0);
                int end=min(i+k,(int)nums.size()-1);
                for(int j=start;j<=end;j++){
                    arr.insert(j);
                }
            }
        }
        vector<int> ans;
        for(auto & it: arr){
            ans.push_back(it);
        }
        return ans;
    }
};