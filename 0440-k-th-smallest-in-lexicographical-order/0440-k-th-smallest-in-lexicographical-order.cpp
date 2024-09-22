class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int count = getCount(n, curr);
            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

private:
    int getCount(int n, int prefix) {
        long long curr = prefix;
        long long next = prefix + 1;
        int count = 0;
        
        while (curr <= n) {
            count += (int)(min((long long)n + 1, next) - curr);
            curr *= 10;
            next *= 10;
        }
        
        return count;
    }
};
