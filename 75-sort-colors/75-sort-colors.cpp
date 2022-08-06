class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l{}, m{}, h{static_cast<int> (nums.size() - 1)};
        while (m <= h)
            if (nums[m] == 0)
                swap(nums[m++], nums[l++]);
            else if (nums[m] == 1)
                m++;
            else swap(nums[m], nums[h--]);
    }
};