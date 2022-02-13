class Solution {
public:
    void findsubSets(vector<vector<int>> &res, vector<int> &nums, int i) {
        int j = 0;
        vector<int> v;
        while (i > 0) {
            if ((i & 1) == 1) v.emplace_back(nums[j]);
            j++;
            i = i >> 1;
        }
        res.emplace_back(v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
            findsubSets(res, nums, i);
        return res;
    }
};