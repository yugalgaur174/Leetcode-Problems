class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int k=0;
        for(int i=0;i<a.size();i++){
           if(st.empty()){
            st.push(a[i]);
           }
           else if(st.top()<0 && a[i]<0){
            st.push(a[i]);

           }
           else if(st.top()>0 && a[i]>0){
            st.push(a[i]);
           }
           else if(st.top()>0 && a[i]<0){
            while(!st.empty() && st.top()>0 && abs(st.top())<=abs(a[i])){
                if(abs(st.top())==abs(a[i])){
                    k=1;
                    st.pop();
                    break;
                }
                st.pop();
            }
            // while(!st.empty())
             if(st.empty() || st.top() < 0) {
                    if(k == 0) st.push(a[i]);
                }

           k = 0;
           }
           else if(st.top()<0){
            st.push(a[i]);
           }
        //     else if(!st.empty() && st.top()<0 && a[i]>0){
        //     while(!st.empty() && a[i]>0 && st.top()<0 && abs(st.top())<=abs(a[i])){
        //         if(abs(st.top())==abs(a[i])){
        //             k=1;
        //         }
        //         st.pop();
        //     }
        //     // while(!st.empty())
        //     if(st.empty() && k==0){
        //     st.push(a[i]);
        //     }
        //    }
            

        }
        vector<int> z;
        
        while(!st.empty()){
            z.push_back(st.top());
            st.pop();
        }
        reverse(z.begin(),z.end());
        return z;
    }
};