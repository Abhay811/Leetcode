class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second) return (a.first < b.first);
        return (a.second < b.second);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i = 0;
        vector<pair<int, int>> v;
        for (auto it : mat)
        {
            int c = 0;
            for (auto it2: it)
                if (it2) c++;
            v.push_back({i, c});
            i++;
        }
        sort(v.begin(), v.end(),cmp);
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.emplace_back(v[i].first);
        return res;
    }
};