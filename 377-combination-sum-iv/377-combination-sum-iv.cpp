class Solution {
public:
    int target;
    vector<int> dp;
    int rec (vector<int>& nums, int idx, int sum=0) {
        if (sum == target)  return 1;
        if (sum > target)   return 0;
        
        if (dp[sum] != -1)  return dp[sum];
        
       int ans = 0;
        for (int i=0 ; i<nums.size() ; i++)
            ans += rec(nums, idx, sum + nums[i]);
        return dp[sum] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int t) {
        target = t;
        dp.resize(t+1, -1);
        return rec(nums, 0);
    }
};