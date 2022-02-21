class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), m = INT_MIN, m2 = INT_MIN, c = 0, c2 = 0;
        for (auto x : nums)
            if (x == m) c++;
            else if (x == m2) c2++;
            else if (c == 0) m = x, c++;
            else if (c2 == 0) m2 = x, c2++;
            else c--, c2--;
        c = 0, c2 = 0;
        for (auto it : nums)
            if (it == m) c++;
            else if (it == m2) c2++;
        vector<int> res;
        if (c > n / 3) res.push_back(m);
        if (c2 > n / 3) res.push_back(m2);
        return res;
    }
};