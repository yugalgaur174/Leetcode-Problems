class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int cnt=0;
        unordered_map<int, pair<bool, bool>>mpp;
        
        for(int i=0;i<A.size();i++){
            mpp[i+1]={false, false};
        }
        for(int i=0;i<A.size();i++){
            mpp[A[i]].first=true;
            if(mpp[A[i]].first==true && mpp[A[i]].second==true){
                cnt++;
            }
            mpp[B[i]].second=true;
            if(mpp[B[i]].first==true && mpp[B[i]].second==true){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};