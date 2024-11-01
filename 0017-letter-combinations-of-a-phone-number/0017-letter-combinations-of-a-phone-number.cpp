class Solution {
public:
    vector<string> ans;
    void make(int i,string s, string digits,vector<string> arr){
        // if(i==digits.size())return;
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        int a = digits[i] - '0';
        for(int j=0;j<arr[a].size();j++){
            make(i+1,s+arr[a][j],digits,arr);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> arr;
        arr.push_back("");
        arr.push_back("");
        arr.push_back("abc");
        arr.push_back("def");
        arr.push_back("ghi");
        arr.push_back("jkl");
        arr.push_back("mno");
        arr.push_back("pqrs");
        arr.push_back("tuv");
        arr.push_back("wxyz");
        string s="";
        if(digits.size()==0)return ans;
        make(0,s,digits,arr);
        return ans;
    }
};