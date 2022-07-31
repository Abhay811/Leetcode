class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start ^ goal, res = 0;
        while (t)
            res += t & 1== 1 ? 1 : 0, t >>= 1;
        return res;
    }
};