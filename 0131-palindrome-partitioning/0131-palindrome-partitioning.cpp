class Solution {
public:
    vector<vector<string>> ans;
    bool check(string a){
        string b=a;
        reverse(a.begin(),a.end());
        return a==b;
    }
    void findans(int i, vector<string> arr, string s, string a){
        cout<<a<<endl;
        if(i==s.size()){
            if(check(a) && a!=""){
                arr.push_back(a);
                // return;
            }
            else{
                return;
            }
            ans.push_back(arr);
            return;
        }
        findans(i+1,arr, s,a+s[i]);
        a+=s[i];
        if(check(a)){
            arr.push_back(a);
            findans(i+1,arr, s,"");
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        string a="";
        string aa="";
        aa+=s[0];
        findans(0,arr,s,"");
        return ans;
    }
};