class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        for (int n = nums.size(); i < n && j < n;)
            if (nums[j] & 1) ++j;
            else swap(nums[i], nums[j]), ++i, ++j;
        return nums;
    }
};