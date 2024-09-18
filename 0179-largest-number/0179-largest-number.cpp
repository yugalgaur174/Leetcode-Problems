class Solution {
public:
static bool customsortt(string & a, string & b){
    return a+b>b+a;
}
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        // arr.push_back(to_string(nums[nums.size()-1]));
        // arr.push_back(to_string(nums[1]));
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(),arr.end(), customsortt);
        string a="";
        if(arr[0]=="0") return "0";


        for(int i=0;i<arr.size();i++){
            
              
            a+=arr[i];
        }
        // a+=arr[0];
        return a;

    }
};