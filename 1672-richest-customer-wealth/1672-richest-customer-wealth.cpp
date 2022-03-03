class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        
        int m = acc.size(), n = acc[0].size(), t = 0, s = 0;
        for (auto it : acc)
        {
            s = accumulate(it.begin(), it.end(), 0);
            t = max (t, s);
        }
        return t;
    }
};