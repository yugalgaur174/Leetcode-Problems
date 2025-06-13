class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        int n=position.size();
        for(int i=0;i<n;i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        stack<pair<int, int>> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({arr[i].first,arr[i].second});
            }
            else{
                int a=st.top().first;
                int b=st.top().second;
                float c=target-a;
                c=(c)/b;
                int d=arr[i].first;
                int e=arr[i].second;
                float f=target-d;
                f=(f)/e;
                if(f>c){
                    st.push({d,e});
                }
            }
        }
        return st.size();
    }
};