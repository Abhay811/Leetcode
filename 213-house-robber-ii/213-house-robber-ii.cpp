class Solution {
public:
    int rob(vector<int>& nums, int l, int r)
    {
        int p = 0, c = 0;
        for (int i = l; i <= r; ++i)
        {
            int t = max (p + nums[i], c);
            p = c;
            c = t;
        }
        return c;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};