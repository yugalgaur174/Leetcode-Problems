class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<int> row = {0, -1, 0, 1 };
        vector<int> col = { 1, 0, -1, 0 };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        int time = 0;
        while (!q.empty()) {
            int n=q.size();
            bool rotten=false;
            for (int j = 0; j < n; j++) {
                auto a = q.front();
                q.pop();
                int b = a.first;
                int c = a.second;
                for (int i = 0; i < 4; i++) {
                    int d = b + row[i];
                    int e = c + col[i];
                    if (d < 0 || e < 0 || d >= grid.size() ||
                        e >= grid[0].size()) {
                        continue;
                    } else {
                        if (grid[d][e] == 1) {
                            grid[d][e]=2;
                            q.push(make_pair(d,e));
                            rotten=true;
                        }
                    }
                }
            }
            if(rotten){
            time++;
            }
            else{
                break;
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};