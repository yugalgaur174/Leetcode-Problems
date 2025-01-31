class Solution {
public:
    const static inline vector<int> DIRECTIONS = { -1, 0, 1, 0, -1 };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n);
        vector<int> size(n * n, 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find;
        find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        int maxIslandSize = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + DIRECTIONS[k], y = j + DIRECTIONS[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int parentA = find(x * n + y);
                            int parentB = find(i * n + j);
                            if (parentA != parentB) {
                                parent[parentA] = parentB;
                                size[parentB] += size[parentA];
                                maxIslandSize = max(maxIslandSize, size[parentB]);
                            }
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    int potentialSize = 1;
                    unordered_set<int> visited;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + DIRECTIONS[k], y = j + DIRECTIONS[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                            int root = find(x * n + y);
                            if (visited.count(root) == 0) {
                                visited.insert(root);
                                potentialSize += size[root];
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }

        return maxIslandSize;
    }
};
