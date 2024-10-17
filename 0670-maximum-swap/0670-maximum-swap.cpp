class Solution {
public:
    int maximumSwap(int num) {
        vector<int> a;
        int k = num;
        while (num > 0) {
            a.push_back(num % 10);
            num /= 10;
        }
        reverse(a.begin(), a.end());
        
        vector<int> b(a);
        vector<int> sorted_a(a);
        sort(sorted_a.begin(), sorted_a.end(), greater<int>());
        
        int n = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != sorted_a[i]) {
                n = i;
                break;
            }
        }
        
        if (n == -1) return k;
        
        int index = -1;
        for (int i = a.size() - 1; i > n; i--) {
            if (a[i] == sorted_a[n]) {
                index = i;
                break;
            }
        }
        
        swap(a[n], a[index]);
        
        num = 0;
        for (int i = 0; i < a.size(); i++) {
            num = num * 10 + a[i];
        }
        
        return num;
    }
};
