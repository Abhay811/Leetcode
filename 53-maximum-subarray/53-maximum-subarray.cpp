class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size(), m;
        vector<int> dp(size);
        dp[0] = m = nums[0];
        for (int i = 1; i < size; ++i)
        {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            m = max (m, dp[i]);
        }
        return m;
    }
};