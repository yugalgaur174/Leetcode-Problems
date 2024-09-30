class CustomStack {
private:
    int * arr;
    int i;
    int size;
public:
    CustomStack(int maxSize) {
        arr=new int[maxSize];
        i=0;
        size=maxSize;
    }
    
    void push(int x) {
        if(i==size) return;
        arr[i]=x;
        i++;
    }
    
    int pop() {
        if(i==0) return -1;
        return arr[--i];
    }
    
    void increment(int k, int val) {
        for(int j=0;j<min(k,size);j++){
            arr[j]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */