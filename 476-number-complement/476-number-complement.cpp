class Solution {
public:
    int findComplement(int num) {
        int m = num, t = 1;
        while (num >>= 1)
            t |= t << 1;
        return t ^ m;
    }
};