class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> arr;
        vector<int> ans;
        int z=0;
        for(int i=0;i<words.size();i++){
            string a=words[i];
            if((a[0]=='a' ||a[0]=='e' ||a[0]=='i' ||a[0]=='o' ||a[0]=='u' ) && (a.back()=='a' ||a.back()=='e' ||a.back()=='i' ||a.back()=='o' ||a.back()=='u' )){
                z++;
            }
            arr.push_back(z);
        }
        for(int i=0;i<queries.size();i++){
            int m=arr[queries[i][1]];
            if(queries[i][0]>0 ){
                m-=arr[queries[i][0]-1];
            }
            // if(queries[i][0]==queries[i][1]){
            //     m+=arr[queries[i][0]];
            // }
            ans.push_back(m);
        }
        return ans;
    }
};