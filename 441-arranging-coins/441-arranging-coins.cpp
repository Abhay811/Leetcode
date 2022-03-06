class Solution {
public:
    int arrangeCoins(int n) {
        // int i = 1;
        // while (i <= n)
        // {
        //     n -= i;
        //     ++i;
        // }
        // return i - 1;
        return floor(-0.5 + sqrt((double) 2 * n + 0.25));
    }
};