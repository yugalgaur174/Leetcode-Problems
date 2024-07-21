class Solution {
public:
     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        if (rowOrder.empty() || colOrder.empty()) return {};
                    unordered_map<int, int> rowPos, colPos;
            for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            int r = rowPos[i];
            int c = colPos[i];
            matrix[r][c] = i;
        }
        return matrix;
    }

private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
           vector<int> inDegree(k + 1, 0);
        unordered_map<int, unordered_set<int>> graph;
        
        for (const auto& cond : conditions) {
            int u = cond[0], v = cond[1];
            if (graph[u].insert(v).second) {
                ++inDegree[v];
            }
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for (int neighbor : graph[node]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return order.size() == k ? order : vector<int>();
    }
};