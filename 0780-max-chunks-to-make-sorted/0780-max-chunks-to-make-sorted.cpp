class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int max=-1;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
            }
            if(max==st.size()){
                // st.clear();
                ans++;
            }
            st.push(arr[i]);
        }
        return ans;
    }
};