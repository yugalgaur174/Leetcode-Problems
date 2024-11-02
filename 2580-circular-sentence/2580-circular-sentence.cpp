class Solution {
public:
    bool isCircularSentence(string sentence) {
        int l=sentence.size();
        if(l==1) return true;
        char a=sentence[0];
        stringstream ss(sentence);
        string word;
        char prev=sentence[0];
        string lastword;
        while(ss>> word){
            if(word[0]!=prev){
                return false;
            }
            prev=word[word.size()-1];
            lastword=word;
        }
        if(lastword[lastword.size()-1]!=a){
            return false;
        }
        return true;
    }
};