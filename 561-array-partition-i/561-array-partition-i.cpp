class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        for (int i = 0, n = nums.size(), j = 1; j < n; i += 2, j += 2)
            s += min(nums[i], nums[j]);
        return s;
    }
};