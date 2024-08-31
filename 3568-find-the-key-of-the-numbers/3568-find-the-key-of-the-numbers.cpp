class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int a;
        a = min(num1 % 10, num2 % 10);
        a = min(a, num3 % 10);
        num1 /= 10;
        num2 /= 10;
        num3 /= 10;
        for (int i = 1; i < 4; i++) {
            int z = min(num1 % 10, num2 % 10);
            z = min(z, num3 % 10);
            a = a + (pow(10,i))*z;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return a;
    }
};