class Solution {
public:
    int rob(vector<int>& nums) {
        
        int s = nums.size();
        if (s == 1)
            return nums[0];
        vector<int> dp(3);
        dp[0] = nums[0];
        dp[1] = max (nums[0], nums[1]);
        for (int i = 2; i < s; i++)
        {
            dp[2] = max (dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[1];
    }
};