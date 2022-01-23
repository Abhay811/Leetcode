class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &nums, int t)
    {
        if (t == nums.size())
        {
            res.emplace_back(nums);
            return;
        }
        for (int j = t; j < nums.size(); j++)
        {
            swap(nums[t], nums[j]);
            solve(res, nums, t + 1);
            swap(nums[t], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, 0);
        return res;
    }
};