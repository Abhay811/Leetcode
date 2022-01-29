class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int l = 1;
        int r = 65536;
        long long m = 0;
        while (l <= r)
        {
            m = (l + r) / 2;
            long long t = m * m;
            if (t == x)
                return m;
            else if (t < x)
                l = m + 1;
            else
                r = m - 1;
            
        }
        if (m * m < x)
            return m;
        else return m - 1;
    }
};