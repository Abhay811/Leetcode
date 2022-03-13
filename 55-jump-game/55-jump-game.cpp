class Solution {
public:
    bool canJump(vector<int>& nums) {
        int s = nums.size() - 1;
        for (int i = s; i >= 0; --i)
            if (i + nums[i] >= s)
                s = i;
        return s == 0 ? true : false;
    }
    
};