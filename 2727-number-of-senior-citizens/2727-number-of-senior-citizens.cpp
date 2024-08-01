class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=0;
        for(int i=0;i<details.size();i++){
            int a=stoi(details[i].substr(11,2));
            if(a>60){
                n++;
            }
        }
        return n;
    }
};