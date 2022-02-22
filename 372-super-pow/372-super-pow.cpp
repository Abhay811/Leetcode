class Solution {
public:
    const int m = 1337;
    int solve(int a, int b, int m)
    {
        int res = 1;
        a %= m;
        while (b)
        {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int n = 0;
        for (int i = 0, size = b.size(); i < size; ++i)
            n = (n * 10 + b[i]) % 1140;
        return solve(a, n, m);
    }
};