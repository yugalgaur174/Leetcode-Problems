class Solution {
public:
    void check(string &s){
        string a="AB";
        string b="CD";
        size_t pos=s.find(a);
        if(pos!=string::npos){
            s.erase(pos,2);
            check(s);
        }
        pos=s.find(b);
        if(pos!=string::npos){
            s.erase(pos,2);
            check(s);
        }
        return;
    }
    int minLength(string s) {
        check(s);
        return s.size();
    }
};