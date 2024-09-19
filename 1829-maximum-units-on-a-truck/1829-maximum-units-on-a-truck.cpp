class Solution {
public:
    static bool srt(vector<int>& a,vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),srt);
        // return boxTypes[1][0]
        int ans=0,i=0;
        while(truckSize>0&& i < boxTypes.size()){
            while(boxTypes[i][0]>0 && truckSize>0){
                ans+=boxTypes[i][1];
                boxTypes[i][0]--;
                truckSize--;
            }
            i++;
        }
        return ans;
    }
};