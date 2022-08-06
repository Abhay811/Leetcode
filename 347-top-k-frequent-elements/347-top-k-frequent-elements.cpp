class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto it : nums) mp[it]++;
        for (auto it : mp)
            bucket[it.second].emplace_back(it.first);
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; --i)
            for (auto n : bucket[i])
            {
                res.emplace_back(n);
                if (res.size() == k) break;
            }
        return res;
    }
};