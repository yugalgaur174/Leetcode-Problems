class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        if(original.size()!=m*n){
            return {};
        }
        
        else{
            int k=0;
        int j=0;
            for(int i=0;i<m*n;i++){
                if(k==n) {
                    j++ ; k=0;
                
                }
                arr[j][k]=original[i];
                k++;
            }
        }
        return arr;
    }
};