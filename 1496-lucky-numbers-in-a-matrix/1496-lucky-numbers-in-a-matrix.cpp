class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minRowValues(m, INT_MAX);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minRowValues[i] = min(minRowValues[i], matrix[i][j]);
            }
        }
        vector<int> maxColValues(n, INT_MIN);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                maxColValues[j] = max(maxColValues[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRowValues[i] && matrix[i][j] == maxColValues[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }
        
        return luckyNumbers;
    }
};