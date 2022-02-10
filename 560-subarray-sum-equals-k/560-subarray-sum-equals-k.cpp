class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0, currSum = 0, n = nums.size();
        for (auto &it : nums)
        {
            currSum += it;
            if (currSum == k)
                res++;
            if (mp.count(currSum - k))
                res += mp[currSum - k];
            mp[currSum]++;
        }
        return res;
    }
};