class MedianFinder {
public:
    priority_queue<double> lpq;
    priority_queue<double, vector<double>, greater<double>> spq;
    int n;
    MedianFinder() {
        n=0;

    }
    
    void addNum(int num) {
        n++;
        if(lpq.empty()){
            lpq.push(num);
            return;
        }
        if(spq.empty()){
            if(lpq.top()>num){
                int a=lpq.top();
                lpq.pop();
                spq.push(a);
                lpq.push(num);
            }
            else{
                spq.push(num);
            }
            return;
        }
        int a=spq.top();
        int b=lpq.top();
        if(n%2==1){
            if(a<num){
                lpq.push(a);
                spq.push(num);
                spq.pop();
            }
            else{
                lpq.push(num);
            }
        }
        else{
            if(b>num){
                spq.push(b);
                lpq.pop();
                lpq.push(num);
            }
            else{
                spq.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(n%2==1){
            return lpq.top();
        }
        int a=spq.top();
        int b=lpq.top();
        return (double)(a+b)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */