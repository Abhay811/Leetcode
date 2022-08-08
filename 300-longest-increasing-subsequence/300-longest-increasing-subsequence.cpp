class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto it : nums) {
            if (res.empty() || res[res.size() - 1] < it)
                res.emplace_back(it);
            else
            {
                auto t = lower_bound(res.begin(), res.end(), it);
                *t = it;
            }
        }
        return res.size();
    }
};