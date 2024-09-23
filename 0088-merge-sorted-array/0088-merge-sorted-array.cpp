class Solution {
    private:
    void swapp(vector<int> &nums1, vector<int> &nums2, int left, int right) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
        }
    }

    public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int len = n + m;
        int gap = (len + 1) / 2;
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // arr1 and arr2
                if (left < n && right >= n) {
                    swapp(arr1, arr2, left, right - n);
                }
                // arr2 and arr2
                else if (left >= n) {
                    swapp(arr2, arr2, left - n, right - n);
                }
                // arr1 and arr1
                else {
                    swapp(arr1, arr1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1) break;
            gap = (gap + 1) / 2;  // Correct gap halving logic
        }
        for (int i = 0; i < m; ++i) {
            arr1[n + i] = arr2[i];
        }
    }
};
