class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            dist[a][b]=c;
            dist[b][a]=c;
        }
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]!=INT_MAX && dist[via][j]!=INT_MAX && dist[i][j]>dist[i][via]+dist[via][j]){
                        dist[i][j]=dist[i][via]+dist[via][j];
                        dist[j][i]=dist[i][via]+dist[via][j];

                    }
                }
            }
        }
        vector<int> arr(n,0);
        int m=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    arr[i]++;
                }
            }
                    if(m>arr[i]){
                        m=arr[i];
                    }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==m){
                return i;
            }
        }
        return 0;
    }
};