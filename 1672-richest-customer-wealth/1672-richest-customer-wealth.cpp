class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        
        int m = acc.size(), n = acc[0].size(), t = 0, s = 0;
        for (int i = 0; i < m; i++) {
            s = 0;
            for (int j = 0; j < n; j++)
                s += acc[i][j];
            if (t < s)
                t = s;
        }
        return t;
    }
};