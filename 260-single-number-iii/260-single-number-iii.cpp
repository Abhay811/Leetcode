class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long t = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        t &= -t;
        vector<int> res{0, 0};
        for (auto it : nums)
            if ((it & t) == 0)
                res[0] ^= it;
            else
                res[1] ^= it;
        
        return res;
        
    }
};