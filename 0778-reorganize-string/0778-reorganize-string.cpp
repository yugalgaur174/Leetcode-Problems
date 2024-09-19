class Solution {
public:
    string a="";
    bool possible(string s){
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto & m:mpp){
            // if(m.second>0){
                pq.push({m.second,m.first});
            // }
        }
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            for(int i=0;i<=1;i++){
                if(!pq.empty()){
                    auto freq=pq.top();
                    pq.pop();
                    freq.first--;
                    a+=freq.second;
                    if(freq.first>0)temp.push_back(freq);
                }
                else{
                    if(!temp.empty())
                        return false;
                }
            }
            for(auto & i:temp){
                // if(i.first>0){
                pq.push(i);
                // }
            }

        }
        return true;
    }
    string reorganizeString(string s) {
        a="";
        if(!possible(s)){
            return "";
        }
        return a;
    }
};