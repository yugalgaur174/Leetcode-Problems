class Solution {
public:
    int bloom(vector<int> bloomDay, int mid, int k){
        int conti=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            bloomDay[i]-=mid;
            if(bloomDay[i]<=0){
                conti++;
            }
            else{
                conti=0;
            }
            if(conti==k){
                ans++;
                conti=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long mm=m, kk=k;
        long long need=mm*kk;
        if(n<need){
            return -1;
        }
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        if(need==n){
            return maxi;
        }
        int low=0;
        int high=maxi;
        int ans=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int no=bloom(bloomDay,mid,k);
            if(no==m){
                ans=mid;
                high=mid-1;
            }
            if(no<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};