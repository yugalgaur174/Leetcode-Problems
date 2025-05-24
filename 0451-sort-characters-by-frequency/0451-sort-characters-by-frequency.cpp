class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            if(freq_map[a]==freq_map[b]){
                return a<b;
            }
            return freq_map[a] > freq_map[b];
        });

        return s;
    }
};

// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> mpp;
//         for(int i=0;i<s.size();i++){
//             mpp[s[i]]++;
//         }
//         vector<pair<int,char>> freq;
//         for(auto& entry:mpp){
//             freq.push_back({entry.second,entry.first});
//         }
//         sort(freq.begin(),freq.end());
//         string a;
//         for(auto&entry:freq){
//             for(int i=0;i<entry.first;i++){
//                 a+=entry.second;
//             }
//         }
//         string ans="";
//         for(int i=a.size()-1;i>=0;i--){
//             ans+=a[i];
//         }
//         return ans;
//     }
// };