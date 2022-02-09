class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> res;
        for (auto it : nums)
            res[it]++;
        int ans = 0;
        for (auto it : res)
        {
            if (k == 0)
            {
                if (it.second > 1)
                    ans++;
            }
            else if (res.find(it.first + k) != res.end())
                ans++;
        }
        return ans;
    }
};