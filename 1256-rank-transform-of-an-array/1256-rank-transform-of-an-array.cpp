class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans=arr;
        unordered_map<int,int>mpp;
        set<int>st;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
        }
        auto z=st.begin();
        for(int i=0;i<st.size();i++){
            mpp[*z++]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            ans[i]=mpp[ans[i]];
        }
        return ans;
    }
};