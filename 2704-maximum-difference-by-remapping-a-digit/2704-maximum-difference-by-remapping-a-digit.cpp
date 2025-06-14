class Solution {
public:
    int minMaxDifference(int num) {
        stack<int> st;
        int a=9;
        int n=num;
        while(n>0){
            int z=n%10;
            if(z==9){
                st.push(n%10);
            n/=10;
                continue;
            }
            else{
                a=z;
            }
            st.push(n%10);
            n/=10;
        }
        int maxi=0;
        while(!st.empty()){
            int c=st.top();
            if(c==a){
                maxi=maxi*10+9;
                st.pop();
                continue;
            }
            maxi=maxi*10+st.top();
            st.pop();
        }
        a=0;
        n=num;
        while(n>0){
            int z=n%10;
            if(z==0){
                 st.push(n%10);
            n/=10;
                continue;
            }
            else{
                a=z;
            }
            st.push(n%10);
            n/=10;
        }
        int mini=0;
        while(!st.empty()){
            int c=st.top();
            if(c==a){
                mini=mini*10;
            }
            else{
                mini=mini*10+st.top();

            }
            st.pop();
        }
        return maxi-mini;
    }
};