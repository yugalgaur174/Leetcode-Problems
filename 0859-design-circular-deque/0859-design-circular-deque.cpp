class MyCircularDeque {
private:
int front=-1,back=-1;
int kk=0,size=0;
int *arr;
public:
    MyCircularDeque(int k) {
        arr=new int[k];
        front=-1;
        back=-1;
        size=0;
        kk=k;
    }
    
     bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {  
            front = 0;
            back = 0;
        } else {
            front = (front + 1) % kk;
        }
        arr[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {  
            front = 0;
            back = 0;
        } else {
            back = (back - 1 + kk) % kk;
        }
        arr[back] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        if (front == back) {  
            front = -1;
            back = -1;
        } else {
            front = (front - 1 + kk) % kk;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (front == back) {  
            front = -1;
            back = -1;
        } else {
            back = (back + 1) % kk;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
    if (isEmpty()) return -1;
        return arr[back];
        
    }
    
    bool isEmpty() {
        if(size==0) return true;
        return false;
    }
    
    bool isFull() {
        
        if(size==kk) return true;
        return false; 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */