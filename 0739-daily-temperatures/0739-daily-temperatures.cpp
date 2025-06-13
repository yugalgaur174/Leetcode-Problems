class Solution {
public:
    vector<int> dailyTemperatures(vector<int> temperatures) {
        stack<pair<int, int>> st;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                    st.push({temperatures[i],i});
                temperatures[i]=0;
                continue;
            }
            else{
                while(!st.empty() && st.top().first<=temperatures[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push({temperatures[i],i});
                    temperatures[i]=0;
                }
                else{
                    int a=temperatures[i];
                    temperatures[i]=st.top().second-i;
                    st.push({a,i});
                }
            }
        }
        return temperatures;
    }
};