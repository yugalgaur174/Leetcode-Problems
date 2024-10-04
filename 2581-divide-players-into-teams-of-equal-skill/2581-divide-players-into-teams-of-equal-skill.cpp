class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size()==2) return (skill[1]*skill[0]);
        long long sum=0;
        // int a;
        // unordered_map<int,int> mpp;
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        sum=skill[i]+skill[j];
        long long ans=skill[i]*skill[j];
        i++;j--;
        while(i<=j){
            if(skill[i]+skill[j]==sum){
                ans+=skill[i]*skill[j];
                i++;
                j--;
            }
            else{
                return -1;
            }
        }
        return ans;
        // for(int i=0;i<skill.size();i++){
        //     mpp[skill[i]]++; 
        //     sum+=skill[i];
        // }
        // if(sum%(skill.size()/2)==0){
        //     a=sum/(skill.size()/2);
        // }
        // else{
        //     return -1;
        // }
        // return a;
    }
};