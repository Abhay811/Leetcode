class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t)
    {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0, size = nums.size(); i < size; ++i)
        {
            int r = t - nums[i];
            if (mp.find(r) != mp.end())
                return {mp[r], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};