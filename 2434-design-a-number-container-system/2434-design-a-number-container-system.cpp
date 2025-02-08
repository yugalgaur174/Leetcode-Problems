class NumberContainers {
public:
    unordered_map<int, set<int>> mpp;
    unordered_map<int, int> adding;
    NumberContainers() {}

    void change(int index, int number) {
        if (adding[index] != 0) {
            int a = adding[index];
            mpp[a].erase(index);
            if (mpp[a].empty()) {
                mpp.erase(a);
            }
        }
        
        adding[index] = number;
        mpp[number].insert(index);
    }

    int find(int number) {
        if (mpp[number].empty()) {
            return -1;
        }
        return *mpp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */