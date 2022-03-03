class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return 0;
        int c = 0, d;
        for (int i = 0; i < size - 2; ++i)
        {
            d = nums[i + 1] - nums[i];
            for (int j = i + 2; j < size; ++j)
                if (nums[j] - nums[j - 1] == d)
                    ++c;
                else break;
        }
        return c;
    }
};