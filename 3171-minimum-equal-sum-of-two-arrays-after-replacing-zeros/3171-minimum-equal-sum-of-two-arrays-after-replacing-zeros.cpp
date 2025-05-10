class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1=0,z2=0;
        // cout<<z1<<endl;
        long long sum1=0, sum2=0;
        for(int i=0;i<nums1.size();i++){
            // cout<<"z1"<<z1<<endl;
            if(nums1[i]==0)z1++;
            sum1+=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            // cout<<"nums2[i]"<<nums2[i]<<endl;
            if(nums2[i]==0)z2++;
            sum2+=nums2[i];
        }
        // cout<<"z1"<<z1<<" z2"<<z2<<endl;
        if(z1==0 && sum1<sum2+z2)return -1;
        if(z2==0 && sum2<sum1+z1) return -1;
        if(z1!=0 && z2!=0){
            long long a=sum1+z1;
            long long b=sum2+z2;
            // cout<<"a"<<a<<" "<<"b"<<b<<endl;
            return max(a,b );
        }
        else if(z1==0){
            return sum1;
        }
        else if(z2==0){
            return sum2;
        }
        else {
            return -1;
        }
    }
};