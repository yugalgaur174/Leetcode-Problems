class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                a++;
            }
            else if(nums[i]==1){
                b++;
            }
            else {
                c++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(a>0){
                nums[i]=0;
                a--;
            }
            else if(b>0){
                nums[i]=1;
                b--;
            }
            else{
                nums[i]=2;
                c--;
            }
        }
        
    }
};