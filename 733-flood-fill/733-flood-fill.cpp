class Solution {
    void floodFill(vector<vector<int>> &image, int x, int y, int pc, int nc, int m, int n)
    {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return;
        if (image[x][y] != pc)
            return;
        if (image[x][y] == nc)
            return;
        image[x][y] = nc;
        floodFill(image, x + 1, y, pc, nc, m, n);
        floodFill(image, x - 1, y, pc, nc, m, n);
        floodFill(image, x, y + 1, pc, nc, m, n);
        floodFill(image, x, y - 1, pc, nc, m, n);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        floodFill(image, sr, sc, image[sr][sc], newColor, m, n);
        return image;
    }
};