class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        int size = nums.size();
        unordered_map<int, int> c;
        c[nums[size - 1] - nums[size - 2]] = 1;
        for (int b = size - 3; b >= 1; b--)
        {
            for (int a = b - 1; a >= 0; a--)
                res += c[nums[a] + nums[b]];
            for (int x = size - 1; x > b; x--)
                c[nums[x] - nums[b]]++;
        }
        return res;
    }
};