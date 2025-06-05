class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, set<char>> adj;
        for (int i = 0; i < s1.size(); i++) {
            adj[s1[i]].insert(s2[i]);
            adj[s2[i]].insert(s1[i]);
        }
        unordered_map<char, char> minchar;
        vector<unordered_set<char>> st;
        vector<int> visited(26, 0);

        string aa = s1 + s2;
        for (char c : aa) {
            if (!visited[c - 'a']) {
                set<char> component;
                queue<char> q;
                q.push(c);
                visited[c - 'a'] = 1;
                while (!q.empty()) {
                    char curr = q.front();
                    component.insert(curr);
                    q.pop();
                    for (char a : adj[curr]) {
                        if (!visited[a - 'a']) {
                            visited[a-'a']=1;
                            q.push(a);
                        }
                    }
                }
                char small=*component.begin();
                for(char ch:component){
                    minchar[ch]=small;
                }
            }
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            if(minchar.count(baseStr[i])){

            ans+=minchar[baseStr[i]];
            }
            else ans+=baseStr[i];
        }
        return ans;
    }
};