class Solution {
public:
        unordered_map<string, int> mpp;
        vector<vector<string>> ans;
        string b;
    void dfs(string word,vector<string> seq){
        if(b==word){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[word];
        for(int i=0;i<word.size();i++){
            char orig=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=orig;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        b=beginWord;
        mpp[beginWord]=1;
        st.erase(beginWord);
        int size=beginWord.size();
        while(!q.empty()){
            string word=q.front();
            q.pop();
            int steps=mpp[word];
            if(word==endWord){
                break;
            }
            for(int i=0;i<size;i++){
                char orig=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=orig;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};