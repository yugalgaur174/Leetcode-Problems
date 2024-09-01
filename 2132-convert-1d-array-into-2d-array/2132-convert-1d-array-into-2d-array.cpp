class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        if(original.size()!=m*n){
            return {};
        }
        
        
            
            for(int i=0;i<m*n;i++){
                
                arr[i/n][i%n]=original[i];
                
            }
        
        return arr;
    }
};