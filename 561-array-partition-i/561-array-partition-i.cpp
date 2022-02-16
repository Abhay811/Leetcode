class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        for (int i = 0, n = nums.size(); i < n; i += 2)
            s += nums[i];
        return s;
    }
};