class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (memo[r][c] != -1) return memo[r][c];

        int moves = 0;
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        for (auto [dr, dc] : directions) {
            int newRow = r + dr, newCol = c + dc;

            if (newRow >= 0 && newRow < grid.size() && newCol < grid[0].size() &&
                grid[newRow][newCol] > grid[r][c]) {
                moves = max(moves, 1 + dfs(newRow, newCol, grid, memo));
            }
        }

        memo[r][c] = moves;
        return moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxMoves = 0;

        vector<vector<int>> memo(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            maxMoves = max(maxMoves, dfs(i, 0, grid, memo));
        }

        return maxMoves;
    }
};
