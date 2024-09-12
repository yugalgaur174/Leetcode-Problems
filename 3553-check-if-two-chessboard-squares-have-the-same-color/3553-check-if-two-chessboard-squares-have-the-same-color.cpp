class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a=coordinate1[0]-'a'+1;
        int b=coordinate1[1]-'0';
        int c=coordinate2[0]-'a'+1;
        int d=coordinate2[1]-'0';
        if(((a+b)%2)==((c+d)%2)) return true;
        return false;
    }
};