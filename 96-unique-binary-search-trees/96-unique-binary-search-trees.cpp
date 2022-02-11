class Solution {
public:
    int numTrees(int n) {
        long double res = 1;
        for (int k = 2; k <= n; k++)
            res *= (n + k), res /= k;
        return res;
    }
};