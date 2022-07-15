class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int temp = 0;
        while(left != right) 
        {
            ++ temp;
            left >>= 1;
            right >>= 1;
        }
        return left << temp;
    }
};