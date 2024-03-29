class Solution {
public:
    int getSum(int a, int b) {
        
         while (b) {
            uint32_t carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};