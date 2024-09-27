class MyCalendarTwo {
public:
vector<pair<int,int>> arr1,arr2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto& check:arr2){
            if(start<check.second && end>check.first){
                return false;
            }
        }
        for(auto& check:arr1){
            if(start<check.second&& end>check.first){
                arr2.push_back({max(start,check.first),min(end,check.second)});
            }
        }
        arr1.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */