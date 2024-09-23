class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> g(n);
        int k=1;
        while(k<=n){
            g[k-1].resize(k);
            if(k==1){
                g[k-1][0]=1;
            }
            else if(k==2){
                g[k-1][0]=g[k-1][1]=1;
            }
            else{
                g[k-1][0]=1;
                for(int i=1;i<k-1;i++){
                    g[k-1][i]=g[k-2][i-1]+g[k-2][i];
                }
                g[k-1][k-1]=1;
            }
            k++;
        }
        return g;
    }
};



// class Solution {
// public:
//     vector<vector<int>> generate(int n) {
//         vector<vector<int>> g(n);
//         int k=1;
//         while(k<=n){
//             g[k-1].resize(k);
//             if(k==1){
//                 g[0][0]=1;
//             }
//             else if(k==2){
//                 g[k-1][0]=1;
//                 g[k-1][k-1]=1;
//             }
//             else{
//                 g[k-1][0]=1;
//                 for(int i=0;i<k-2;i++){
//                     g[k-1][1+i]=(g[k-2][i]+g[k-2][i+1]);
//                 }
//                 g[k-1][k-1]=(1);
//             }
//             k++;
//         }
//         return g;
//     }
// };