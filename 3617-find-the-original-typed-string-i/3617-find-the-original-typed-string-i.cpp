class Solution {
public:
    int possibleStringCount(string word) {
        // unordered_map<char, int>mpp;
        if(word.size()==0) return 0;
        char z=word[0];
        int ans=1;
        for(int i=1;i<word.size();i++){
            // mpp[word[i]]++;
            if(z==word[i]) ans++;
            z=word[i];
        }
        return ans;
    }
};