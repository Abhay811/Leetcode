class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        bool inc = true, dec = true;
        for (int i = 1; i < size; ++i)
            inc &= nums[i - 1] <= nums[i], dec &= nums[i - 1] >= nums[i];
        return inc || dec;
    }
};