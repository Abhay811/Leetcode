class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        
        while (n > 0) {
            int s = n / 5;
            res += s;
            n = s;
        }
        return res;
    }
};