class Solution {
public:
    int lengthOfLastWord(string s) {
        // string sen;
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word){
            ans=word;
        }
        return ans.size();
    }
};