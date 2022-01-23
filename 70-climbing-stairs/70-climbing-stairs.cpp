class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int a = 3, b = 2;
        while (n > 3)
        {
            int t = a + b;
            b = a;
            a = t;
            n--;
        }
        return a;
    }
};