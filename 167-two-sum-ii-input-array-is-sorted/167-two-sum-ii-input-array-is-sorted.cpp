class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, l = 0, r = n - 1;
        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum < target)
                l += 1;
            else if (sum > target)
                r -= 1;
            else
                return {l + 1, r + 1};
        }
        return {};
    }
};