class Solution {
public:
    int climbStair(int n,vector<int> & arr) {
if(n==0) return 1;
        if(n==1) return 1;
        int left,right;
        if(arr[n-1]!=-1){
            left=arr[n-1];
        }
        else{
            left=climbStair(n-1,arr);
            arr[n-1]=left;
        }
        if(arr[n-2]!=-1){
            right=arr[n-2];
        }
        else{
            right=climbStair(n-2,arr);
            arr[n-2]=right;

        }
        
        return left+right;
    }
    int climbStairs(int n) {
vector<int> arr(n,-1);
        return climbStair(n,arr);
    }
};