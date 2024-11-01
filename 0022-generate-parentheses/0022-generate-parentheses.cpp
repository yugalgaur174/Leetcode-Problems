class Solution {
public:
        set<string> arr;
    void parenthesis(int p,int n, int m,string s){
        if(p==n && p==m){
        cout<<s<<endl;
            arr.insert(s);
            return ;
        }
        if(n>p ||p>m ||n>m)return;

        if(p==n){
            parenthesis(p+1,n,m,s+"(");
            // parenthesis()
        }
        parenthesis(p+1,n,m,s+"(");

        parenthesis(p,n+1,m,s+")");
    }
    vector<string> generateParenthesis(int n) {
        // if(n==0) return arr;
        vector<string> arr1;
        string s="";
        parenthesis(1,0,n,s+"(");
        for(auto & it: arr){
            arr1.push_back(it);
        }
        return arr1;
    }
};