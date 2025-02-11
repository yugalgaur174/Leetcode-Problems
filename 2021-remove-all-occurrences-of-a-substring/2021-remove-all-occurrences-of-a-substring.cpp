class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(part.size()>s.size()){
            return s;
        }
        if(part==s){
            return "";
        }
        size_t pos=s.find(part);
        while(pos!=string::npos){
            s.erase(pos,part.size());
            pos=s.find(part);
        }
        return s;
    }
};