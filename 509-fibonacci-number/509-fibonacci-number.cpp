class Solution {
public:
    int fib(int n) {
        int v[2] = {0, 1};
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int prevInd = 1;
        int secondlastInd = 0;
        for (int i = 2; i <= n; i++)
        {
            int t = v[prevInd] + v[secondlastInd];
            v[secondlastInd] = v[prevInd];
            v[prevInd] = t;
        }
        return v[prevInd];
    }
};