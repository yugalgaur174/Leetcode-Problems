class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,vector<int>& initialBoxes) {
        queue<int> q;
        vector<int> key(status.size(), 0);
        vector<int> visited(status.size(), 0);
        vector<int> have(status.size(), 0);
        for (int i = 0; i < initialBoxes.size(); i++) {
            int box = initialBoxes[i];
            have[box] = 1;
            if (status[box] == 1) {
                q.push(box);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            if (visited[a] ) continue;
            visited[a] = 1;
            ans += candies[a];
            for (int i = 0; i < keys[a].size(); i++) {
                int k = keys[a][i];
                key[k] = 1;
                if (have[k] && !visited[k]) {
                    q.push(k); 
                }
            }
            for (int i = 0; i < containedBoxes[a].size(); i++) {
                int b = containedBoxes[a][i];
                have[b] = 1;
                if ((status[b] == 1 || key[b]) && !visited[b]) {
                    q.push(b);
                }
            }
        }

        return ans;
    }
};
