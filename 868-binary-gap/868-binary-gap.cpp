class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        for (int d = -32; N; N /= 2, d++)
            if (N % 2) res = max(res, d), d = 0;
        return res;
    }
};