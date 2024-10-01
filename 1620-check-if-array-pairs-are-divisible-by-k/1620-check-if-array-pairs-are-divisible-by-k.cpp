class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            int a = ((arr[i] % k) + k) % k;
            mpp[a]++;
        }
        for (auto& [a, count] : mpp) {
            if (a == 0) {
                if (count % 2 != 0) return false;
            } else if (mpp[a] != mpp[k - a]) {
                return false;
            }
        }
        return true;
    }
};
