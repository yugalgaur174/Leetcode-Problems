class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        unordered_map<int,int> b;
        for(int i=0;i<nums1.size();i++){
            a[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            b[nums2[i]]++;
        }
        int x=*max_element(nums1.begin(), nums1.end());
        int y=*max_element(nums2.begin(), nums2.end());
        int z=0;
        if(x>y) z=y;
        else z=x;
        vector<int> c;
        for(int i=0;i<z+1;i++){
            if(a[i]<=b[i]){
                for(int j=0;j<a[i];j++){
                    c.push_back(i);
                }
            }
            else{
                for(int j=0;j<b[i];j++){
                    c.push_back(i);
                }
            }
        }
        return c;
    }
};