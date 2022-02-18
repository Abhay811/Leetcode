class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<vector<int>> res;
        vector<int> r{1};
        res.emplace_back(r);
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> row;
            for (int j = 0; j < i + 1; ++j)
                if (j == 0 || j == i) row.emplace_back(1);
                else row.emplace_back(res[i - 1][j - 1] + res[i - 1][j]);
            res.emplace_back(row);
        }
        return res[rowIndex];
    }
};