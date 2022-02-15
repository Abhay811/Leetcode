class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for (int i = 0, size = nums.size(); i < size; i++)
            s ^= nums[i];
        return s;
    }
};