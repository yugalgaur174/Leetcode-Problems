class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>>pq;
        unordered_map<char, int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto & it: mpp){
            pq.push({it.first,it.second});
        }
        // pair<char, int> a;
        int n=s.size();
        int i=0;
        string ans="";
        while(!pq.empty()){
             auto [ch1, freq1]=pq.top();
            pq.pop();
            int count=min(freq1, repeatLimit);
            ans += string(count, ch1);
            freq1-=count;
            if(freq1>0){
                if(pq.empty()) break;
                auto [ch2, freq2]=pq.top();
                pq.pop();
                ans+=ch2;
                freq2--;
                if(freq2>0){

                pq.push({ch2, freq2});
                }
                pq.push({ch1, freq1});
            }
        }
        return ans;
    }
};