class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int s = 1, e = 1;
        vector<int> res(size, 1);
        
        for (int i = 0; i < size; ++i)
        {
            res[i] *= s;
            s *= nums[i];
            res[size - 1 - i] *= e;
            e *= nums[size - 1 - i];
        }
        return res;
    }
};