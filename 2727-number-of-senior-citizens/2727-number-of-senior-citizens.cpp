class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=0;
        for(auto i:details){
            int a=stoi(i.substr(11,2));
            if(a>60){
                n++;
            }
        }
        return n;
    }
};