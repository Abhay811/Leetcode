class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0, size = nums.size(); i < size; ++i)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = size - 1;
            while (j < k)
            {
                int t = nums[i] + nums[j] + nums[k];
                if (t < 0) ++j;
                else if (t > 0) k--;
                else
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    int l = nums[j], r = nums[k];
                    while (j < k && nums[j] == l) ++j;
                    while (j < k && nums[k] == r) --k;
                }
            }
        }
        return res;
    }
};