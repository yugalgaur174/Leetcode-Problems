class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string, string >> arr;
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            string b=a;
            sort(a.begin(),a.end());
            arr.push_back({a,b});
        }
        sort(arr.begin(),arr.end());
        vector<string> z;
        z.push_back(arr[0].second);
        ans.push_back(z);
        // cout<<arr[0].second<<endl;
        for(int i=1;i<arr.size();i++){
            if(arr[i].first==arr[i-1].first){
                ans[ans.size()-1].push_back(arr[i].second);
            }
            else{
                vector<string> mm;
                mm.push_back(arr[i].second);
                ans.push_back(mm);
            }
            // cout<<arr[i].second<<endl;
        }
        return ans;
    }
};