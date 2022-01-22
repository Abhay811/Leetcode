class Solution {
    void comb(int i, int k, vector<int> &v, vector<vector<int>>& res, int n)
    {
        if (i > n + 1)
            return;
        if (v.size() == k)
        {
            res.emplace_back(v);
            return;
        }
        v.emplace_back(i);
        comb(i + 1, k, v, res, n);
        v.pop_back();
        comb(i + 1, k, v, res, n);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> res;
        comb(1, k, v, res, n);
        return res;
    }
};