class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sgn = 1;
        for (auto it : nums)
            if (it == 0)
                return 0;
            else 
                sgn *= it > 0 ? 1 : -1;
        return sgn;
    }
};