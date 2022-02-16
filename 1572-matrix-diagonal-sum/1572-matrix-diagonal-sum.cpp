class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s = 0;
        for (int i = 0, n = mat.size(); i < n; ++i)
            for (int j = 0, m = mat[0].size(); j < m; ++j)
                if (i == j) s += mat[i][j];
                else if (i + j == n - 1) s += mat[i][j];
        return s;
    }
};