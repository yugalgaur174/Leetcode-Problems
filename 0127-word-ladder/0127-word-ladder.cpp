class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(a==endWord){
                return b;
            }
            for(int i=0;i<a.size();i++){
                char original=a[i];
                for(char j='a';j<='z';j++){
                    a[i]=j;
                    if(st.find(a)!=st.end()){
                        st.erase(a);
                        q.push({a,b+1});
                    }
                }
                a[i]=original;
            }
        }
        return 0;
    }
};