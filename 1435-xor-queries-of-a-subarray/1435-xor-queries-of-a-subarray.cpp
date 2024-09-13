class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> a;
        for(int i=0;i<queries.size();i++){
            int b=0;
            for(int j=queries[i][0];j<queries[i][1]+1;j++){
                b=b^arr[j];
            }
            a.push_back(b);
        }
        // a.push_back(3^0);
        return a;
    }
};