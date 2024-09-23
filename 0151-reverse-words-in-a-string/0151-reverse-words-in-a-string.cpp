class Solution {
public:
    string reverseWords(string s) {
        string ans="";

        stringstream ss(s);
        s="";
        string word;
        while(ss>> word){
            s=word+" "+s;
        }
        // stringstream ss(s);

        s.erase(s.size()-1,1);
        return s;

        // int back=-1;
        // int front=-1;
        // for(int i=s.size()-1;i>-1;i--){
        //     if(s[i]!=' ' && back==-1){
        //         back=i;
        //     }
        //     if(s[i]==' ' && back!=-1){
        //         if(front!=-1){

        //         for(int j=front;j<back+1;j++){
        //             ans+=s[j];
        //         } 
        //         }
        //         ans+=' ';
        //         back=-1;
        //     }
        //     if(back!=-1 && (i==0 || s[i-1]==' ')){
        //         front=i;
        //     }

        // }
        //  if (back != -1 && front != -1) {
        //     ans += s.substr(front, back - front + 1);
        // }
        // if(ans[ans.size()-1]==' ')ans.pop_back();
        
        // return ans;
    }
};