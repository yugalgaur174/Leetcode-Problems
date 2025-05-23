class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int a=arr[mid]-(mid+1);
            if(a<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return k-(-high-1);
    }
};