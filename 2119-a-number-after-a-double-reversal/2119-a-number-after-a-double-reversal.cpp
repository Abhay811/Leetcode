class Solution {
public:
    int reverse(int num) {
        int t = 0, r;
        while (num) {
            r = num % 10;
            t = t * 10 + r;
            num /= 10;
        }
        return t;
    }
    bool isSameAfterReversals(int num) {
        int r1 = reverse(num);
        int r2 = reverse(r1);
        return num == r2;
    }
};