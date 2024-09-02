class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long m=0;
        for(int i=0;i<n;i++){
            m=m+chalk[i];
        }
        k=k%m;
        for(int i=0;i<n;i++){
            if(k<chalk[i]){
                return i;
                break;
            }
            k=k-chalk[i];
            
        }
        return 0;
    }
};