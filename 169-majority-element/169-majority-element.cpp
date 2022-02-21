class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums[0], c = 1;
        for (auto it : nums)
        {
            if (it == m) c++;
            else c--;
            if (c == 0) m = it, c = 1;
        }
        return m;
    }
};