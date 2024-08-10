class DSU{
public:
    vector<int> parent;
    DSU(int N){
                parent = vector<int>(N);
            iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] != x){ 
               parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y){
        parent[find(x)] = find(y);
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DSU dsu = DSU(4*N*N);
              for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                int root = 4 * (r*N+c);
                char val = grid[r][c];
                if(val != '\\'){
                    dsu.unite(root + 0, root + 1);
                    dsu.unite(root + 2, root + 3);
                }
                if(val != '/'){
                    dsu.unite(root + 0, root + 2);
                    dsu.unite(root + 1, root + 3);
                }
                if(r + 1 < N)
                    dsu.unite(root + 3, (root + 4*N) + 0);
                if(r - 1 >= 0)
                    dsu.unite(root + 0, (root - 4*N) + 3);
                if(c + 1 < N)
                    dsu.unite(root + 2, (root + 4) + 1);
                if(c - 1 >= 0)
                    dsu.unite(root + 1, (root - 4) + 2);
            }
        }
        int ans = 0;
        for(int x = 0; x < 4*N*N; x++){
            if(dsu.find(x) == x)
                ans++;
        }
        return ans;
    }
};