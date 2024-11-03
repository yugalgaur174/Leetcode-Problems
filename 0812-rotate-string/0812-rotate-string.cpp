class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            q1.push(s[i]); 
            q2.push(goal[i]);
        }
        int k=s.size();
        while(k!=0){
            char q=q2.front();
            q2.pop();
            q2.push(q);
            if(q1==q2){
                return true;
            }
            k--;
        }
        return false;
    }
};