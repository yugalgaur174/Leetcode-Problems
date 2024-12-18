class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(),0);
        stack<int>st;
        st.push(0);
        for(int i=prices.size()-1;i>=0;i--){
            while(st.top()>prices[i]){
                st.pop();
            }
            if(st.top()==0){
                ans[i]=prices[i];
            }
            else ans[i]=prices[i]-st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};