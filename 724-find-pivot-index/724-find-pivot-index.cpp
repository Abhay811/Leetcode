class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size(), sum = 0, t = 0;
        for (int i = 0; i < size; ++i)
            sum += nums[i];
        for (int i = 0; i < size; t += nums[i++])
            if (t * 2 == sum - nums[i])
                return i;
        return -1;
    }
};