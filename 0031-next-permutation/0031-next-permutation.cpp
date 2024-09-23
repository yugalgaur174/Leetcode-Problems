class Solution {
public:
    // void findd(vector<int>&nums,vector<vector<int>> & arr, vector<int>&ds, vector<int>& mark){
    //     if(ds.size()==nums.size()){
    //         arr.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(!mark[i]){
    //             ds.push_back(nums[i]);
    //             mark[i]=1;
    //             findd(nums,arr,ds,mark);
    //             mark[i]=0;
    //             ds.pop_back();
    //         }
    //     }
    // }
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
        // vector<int> a=nums;
        // sort(nums.begin(),nums.end());
        // vector<vector<int>>arr;
        // vector<int> ds;
        // vector<int> mark(nums.size(),0);
        // findd(nums,arr,ds,mark);
        // int z;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==a){
        //         z=i;
        //     }
        // }
        // nums=arr[(z+1)%arr.size()];
        
    }
};