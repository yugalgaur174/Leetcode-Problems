class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n=code.size();
        if(k==0){
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
            return ans;
        }
        else if(k<0){
            for(int i=0;i<n;i++){
                int a=0;
                for(int j=1;j<=-k;j++){
                    a+=code[(i-j+n)%n];
                    cout<<(i-j+n)%n<<endl;
                }
                    ans.push_back(a);
            }
                return ans;
        }
        else{
            for(int i=0;i<n;i++){
                int a=0;
                for(int j=1;j<=k;j++){
                    a+=code[(i+j)%n];
                }
                    ans.push_back(a);
            }
                return ans;
        }
        return {};
    }
};