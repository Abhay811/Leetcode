class Solution {
public:
    bool isPowerOfFour(long n) {
        while (n % 4 == 0)
            if (n && !(n & n - 1))
                n >>= 2;
            else return false;
        return n == 1;
    }
};