class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> arr;
        for(int i=0;i<mat.size();i++){
            int a=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    a++;
                }
            }
            arr.push_back(a);
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};