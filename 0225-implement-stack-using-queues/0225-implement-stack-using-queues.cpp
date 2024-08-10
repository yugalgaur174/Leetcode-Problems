class MyStack {
private:
        stack<int> myStack;
public:
    MyStack() {
    }
    
    void push(int x) {

        // int s=myStack.size();
        myStack.push(x);
    }
    
    int pop() {
        //  return myStack.pop();
        int topElement=myStack.top();
        myStack.pop();
        return topElement;
    }
    
    int top() {
        return myStack.top();
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */