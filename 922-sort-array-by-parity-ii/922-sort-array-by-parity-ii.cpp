class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0, c = 0; i < size; ++i)
            if (nums[i] % 2 != 0) c++;
            else if (c > 0) swap(nums[i], nums[i - c]);
        for (int i = 1; i < size / 2; i += 2)
            swap(nums[i], nums[size - i - 1]);
        return nums;
    }
};