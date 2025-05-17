class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& group) {
        vector<string> ans1;
        vector<string> ans2;
        int a=0;
        int b=1;
        for(int i=0;i<group.size();i++){
            if(a==group[i]){
                ans1.push_back(words[i]);
                a^=1;
            }
        }
        for(int i=0;i<group.size();i++){
            if(b==group[i]){
                ans2.push_back(words[i]);
                b^=1;
            }
        }
        if(ans1.size()>ans2.size()){
            return ans1;
        }
        else{
            return ans2;
        }
    }
};