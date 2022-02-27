class Solution {
public:
    void floodFill(vector<vector<char>>& grid, int r, int c, char pc, char nc, int m, int n)
    {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (grid[r][c] != pc) return;
        if (grid[r][c] == nc) return;
        grid[r][c] = nc;
        floodFill(grid, r + 1, c, pc, nc, m, n);
        floodFill(grid, r - 1, c, pc, nc, m, n);
        floodFill(grid, r, c + 1, pc, nc, m, n);
        floodFill(grid, r, c - 1, pc, nc, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                {
                    floodFill(grid, i, j, '1', '0', m, n);
                    res++;
                }
        return res;
    }
};