class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> a,c;
        int aa[arr.size()];
        int b=0;
        for(int i=0;i<arr.size();i++){
            b=b^arr[i];
            aa[i]=b;
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]>0) c.push_back(aa[queries[i][0]-1]^aa[queries[i][1]]);
            else c.push_back(aa[queries[i][1]]);
        }
        // for(int i=0;i<queries.size();i++){
        //     int b=0;
        //     for(int j=queries[i][0];j<queries[i][1]+1;j++){
        //         b=b^arr[j];
        //     }
        //     a.push_back(b);
        // }
        // // a.push_back(3^0);
        return c;
    }
};