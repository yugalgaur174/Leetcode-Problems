class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> a(n,-1);
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=2*n-1;i>n-1;i--){
            while(!st.empty() && st.top()<nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                // a.push_back(-1);
                a[i]=-1;
            }
            else{
                // a.push_back(st.top());
                a[i]=st.top();
            }
            st.push(nums[i]);
        }
        return a;
    }
};