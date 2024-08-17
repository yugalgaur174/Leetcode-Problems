// class Solution {
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         // int sum=0;
//         int max=INT_MIN;
//         int m;
//         for(int i=0;i<points[0].size();i++){
//             if(max<points[0][i]){
//                 max=points[0][i];
//                 m=i;
//             }
//         }
//         int sum=max;
//         for(int i=1;i<points.size();i++){
//             max=INT_MIN;
//             int n=0;
//             for(int j=0;j<points[i].size();j++){
//                 int point=points[i][j]-abs(m-j);
//                 if(max<point){
//                     max=point;
//                     n=j;
//                 }
//             }
//             sum+=max;
//             m=n;
//         }
//         return sum;

//     }
// };
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        using ll = long long;
        int n = points[0].size();
        vector<ll> f(n);
        const ll inf = 1e18;
        for (auto& p : points) {
            vector<ll> g(n);
            ll lmx = -inf, rmx = -inf;
            for (int j = 0; j < n; ++j) {
                lmx = max(lmx, f[j] + j);
                g[j] = max(g[j], p[j] + lmx - j);
            }
            for (int j = n - 1; ~j; --j) {
                rmx = max(rmx, f[j] - j);
                g[j] = max(g[j], p[j] + rmx + j);
            }
            f = move(g);
        }
        return *max_element(f.begin(), f.end());
    }
};