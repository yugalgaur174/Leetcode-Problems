class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = -1, col = -1;
        int n = matrix.size();
        int m = matrix[0].size();
        if (matrix[0][0] == 0) {
                    row = 0;
                    col = 0;
                }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        row = 0;
                    } else if (j == 0) {
                        col = 0;
                    } else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (row == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};