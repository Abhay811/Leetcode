class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (auto it : nums)
        {
            prefix = (prefix + it % k + k) % k;
            res += count[prefix]++;
        }
        // for (auto it : count)
        //     cout << it << " ";
        return res;
    }
};