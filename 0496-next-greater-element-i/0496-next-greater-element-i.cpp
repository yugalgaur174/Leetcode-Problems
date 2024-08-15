class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int j=0;
        vector<int> a;
        while(j<nums1.size()){
            int k=0;
                int m=0;
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==nums1[j]) k++;
                if(k==0){
                    continue;
                }
                else{
                    if(nums2[i]>nums1[j]){
                        a.push_back(nums2[i]); 
                        m++;
                        break;
                    }
                }
            }
            if(m==0) a.push_back(-1); 
            else m--;
            j++;
        }
        return a;
    }
};