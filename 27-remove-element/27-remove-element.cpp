class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = nums.size();
        for (int i = 0; i < res; ++i)
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                res--;
                i--;
            }
        return res;
    }
};