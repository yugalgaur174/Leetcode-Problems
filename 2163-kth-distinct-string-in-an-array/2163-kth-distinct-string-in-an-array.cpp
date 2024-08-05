class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        for(const auto& str: arr){
            mpp[str]++;
        }
        int i=0;
        for(const auto& str:arr){
            if(mpp[str]==1){
                i++;
                if(i==k){
                    return str;
                }
            }
        }
        return "";
    }
};