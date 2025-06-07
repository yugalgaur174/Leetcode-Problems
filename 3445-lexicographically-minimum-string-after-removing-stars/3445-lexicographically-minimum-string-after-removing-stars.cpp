class Solution {
public:
    string clearStars(string s) {
        string ans="";
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>> >pq;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                auto a=pq.top();
                s[-a.second]='$';
                pq.pop();
            }
            else{
                pq.push({s[i],-i});
            }
        }

        for(int i=0;i<s.size();i++){
            if(s[i]=='$'|| s[i]=='*'){
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};