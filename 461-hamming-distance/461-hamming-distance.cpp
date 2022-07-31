class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, t = x ^ y;
        while (t)
            t &= t - 1, res++;
        return res;
    }
};