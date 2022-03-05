class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> dp(20003);
        vector<int> f(10001, 0);
        for (auto &it : nums)
            f[it]++;
        
        dp[1] = f[1];
        dp[2] = max (dp[1], f[2] * 2);
        
        for (int i = 3; i <= maxi; i++)
            dp[i] = max (dp[i - 1], dp[i - 2] + f[i] * i);
        
        return dp[maxi];       
        
    }
};