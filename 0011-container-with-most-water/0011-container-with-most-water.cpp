class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int h=height.size()-1;
        int ans=0;
        while(l<h){
            int m=min(height[l],height[h]);
            int a=m*(h-l);
            ans=max(ans,a);
            if(height[l]<height[h]){
                l++;
            }
            else{
                h--;
            }
        }
        return ans;
    }
};