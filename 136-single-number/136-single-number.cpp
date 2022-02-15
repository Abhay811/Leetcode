class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            s ^= nums[i];
        return s;
    }
};