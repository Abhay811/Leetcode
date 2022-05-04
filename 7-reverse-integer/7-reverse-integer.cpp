class Solution {
public:
    int reverse(int x) {
        long long int res = 0;
        int sign = x > 0 ? 1 : -1;
        
        long long m = abs(x), r;
        cout << m;
        while (m)
        {
            r = m % 10;
            res = res * 10 + r;
            m /= 10;
        }
        return res > INT_MAX ? 0 : sign * res;
    }
};