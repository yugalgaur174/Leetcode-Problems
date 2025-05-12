class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            if(digits[i]!=0){
                for(int j=0;j<digits.size();j++){
                    for(int k=0;k<digits.size();k++){
                        if(i!=j && j!=k && k!=i){
                            if(digits[k]%2==0){
                                int a=digits[i]*100+digits[j]*10+digits[k];
                                ans.push_back(a);
                            }
                        }
                    }
                }
            }
        }
        set<int> st;
        vector<int> ans1;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        for(int i=0;i<st.size();i++){
            ans1.push_back(*next(st.begin(), i));
        }
        sort(ans1.begin(), ans1.end());
        return ans1;
    }
};