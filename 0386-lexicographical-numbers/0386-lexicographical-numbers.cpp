class Solution {
public:
    static bool lexo(int a, int b){
        return to_string(a)<to_string(b);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        sort(arr.begin(),arr.end(),lexo);
        return arr;
    }
};