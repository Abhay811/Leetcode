class Solution {
public:
    int dp[8][16384] = {};
    int maxScore(vector<int>& nums, int i = 1, int mask = 0) {
        int size = nums.size();
        if (i > size / 2) return 0;
        if (!dp[i][mask])
            for (int j = 0; j < size; ++j)
                for (auto k = j + 1; k < size; ++k)
                {
                    int newMask = (1 << j) + (1 << k);
                    if ((mask & newMask) == 0)
                        dp[i][mask] = max(dp[i][mask], i * __gcd(nums[j], nums[k]) + maxScore(nums, i + 1, mask + newMask));
                }
        return dp[i][mask];
    }
};