class Solution {
public:
    int findComplement(int num) {
        int m = num, t = 1, mask = 0;
        while (num)
            mask++, num >>=1;
        while (--mask)
            t |= t << 1;
        return t ^ m;
    }
};