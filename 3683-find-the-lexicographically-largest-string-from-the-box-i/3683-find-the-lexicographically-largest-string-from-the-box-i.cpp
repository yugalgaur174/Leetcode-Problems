class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int n=word.size();
        int a=word[0];
        string ans="";
        for(int i=0;i<word.size();i++){
            if(word[i]>a){
                a=word[i];
                int left=n-numFriends+1;
                int len=min(left,n-i);
                ans=word.substr(i,len);
            }
            else if(word[i]==a){
                int left=n-numFriends+1;
                int len=min(left,n-i);
                string neww=word.substr(i,len);
                if(ans<neww){
                    a=word[i];
                    ans=neww;
                }
            }
        }
        return ans;
    }
};