class Solution {
public:
    int solve(int m, int n, int x) {
        int res = 0;
        for (int i = 1; i <= m; i++)
            res += min(x / i, n);
        return res;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n, mid, res;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (solve(m, n, mid) < k)
                l = mid + 1;
            else r = mid - 1, res = mid;
        }
        return res;
    }
};