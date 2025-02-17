class Solution {
public:
    set<string> st;
     void finding(unordered_map<char, int>& mpp, string s, int n) {
        if (!s.empty()) 
            st.insert(s);

        for (auto& it : mpp) { 
            if (it.second > 0) {
                it.second--;  
                finding(mpp, s + it.first, n);
                it.second++;  
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mpp;
        for(int i=0;i<tiles.size();i++){
            mpp[tiles[i]]++;
        }    
        finding(mpp, "",tiles.size());
        for(auto it: st){
            cout<<it<<" ";
        }
        return st.size();
    }
};