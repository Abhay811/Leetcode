#define A(i) nums[(1 + 2 * i) % (size | 1)]
class Solution {
public:
    
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        auto mid = nums.begin() + size/ 2;
        nth_element(nums.begin(), mid, nums.end());
        int m = *mid;
        
        int i = 0, j = 0, k = size - 1;
        while (j <= k)
            if (A(j) > m)
                swap(A(i++), A(j++));
            else if (A(j) < m)
                swap(A(j), A(k--));
            else j++;
        
    }
};