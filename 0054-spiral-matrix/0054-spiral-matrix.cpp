class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        if (matrix.empty() || matrix[0].empty()) return arr;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, left = 0;
        int bottom = m - 1, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                arr.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                arr.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return arr;
    }
};