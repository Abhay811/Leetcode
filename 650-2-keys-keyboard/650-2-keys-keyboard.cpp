class Solution {
public:
    int minSteps(int n) {
        static const int primes[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        if (n <= 5) return n == 1 ? 0 : n;
        for (auto i : primes)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};