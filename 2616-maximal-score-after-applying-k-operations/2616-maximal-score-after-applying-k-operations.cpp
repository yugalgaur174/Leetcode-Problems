class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            int m=pq.top();
            ans+=m;
            pq.pop();
            
            pq.push(ceil(double(m)/3));
        }
        return ans;
    }
};