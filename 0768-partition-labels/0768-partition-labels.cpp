class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> first;
        unordered_map<char, int> last;
        for(int i=1;i<s.size();i++){
            if(first[s[i]]==0){
                first[s[i]]=i;
            }
        }
        first[s[0]]=0;
        for(int i=s.size()-2;i>=0;i--){
            if(last[s[i]]==0){
                last[s[i]]=i;
            }
        }
        last[s[s.size()-1]]=s.size()-1;
        // for(auto & it: first){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"From end"<<endl;
        // for(auto & it:last){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        vector<int> ans;
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            int curr=first[s[i]];
            int currlast=last[s[i]];
            a=min(a,curr);
            b=max(b, currlast);
            if(b==i){
                ans.push_back(b-a+1);
                a=i+1;
                
            }
        }

        return ans;
    }
};