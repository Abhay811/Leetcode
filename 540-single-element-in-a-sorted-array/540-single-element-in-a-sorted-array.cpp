class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0, size = nums.size(); i < size; ++i)
            res ^= nums[i];
        return res;
    }
};