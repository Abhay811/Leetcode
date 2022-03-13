class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(), jumps = 0, cur = 0, far = 0;;
        for (int i = 0; i < size - 1; ++i)
        {
            far = max (far, i + nums[i]);
            if (i == cur)
            {
                jumps++, cur = far;
            }
        } 
        return jumps;
    }
};