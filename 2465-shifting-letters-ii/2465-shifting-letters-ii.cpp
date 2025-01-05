class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n + 1, 0);

        for (const auto& shift : shifts) {
            int a = shift[0];
            int b = shift[1];
            int c = shift[2];
            if (c == 0) {
                arr[a] -= 1;
                arr[b + 1] += 1;
            } else {
                arr[a] += 1;
                arr[b + 1] -= 1;
            }
        }

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int shift = arr[i] % 26;
            if (shift < 0) shift += 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
