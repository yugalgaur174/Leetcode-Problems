class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    int min=INT_MAX;
    void push(int val) {
        st.push(val);
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        min=INT_MAX;
        stack<int> st2;
        while(st.size()){
            if(st.top()<min){
                min=st.top();
            }
            st2.push(st.top());
            st.pop();
        }
        while(st2.size()){
            st.push(st2.top());
            st2.pop();
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */