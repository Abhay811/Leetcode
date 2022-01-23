class Solution {
public:
    vector<int> c;
    int mini(vector<vector<int>> &tri, int i, int j, int m)
    {
        if (i == m)
            return 0;
        if (c[i] == j)
            return tri[i][j];
        c[i] = j;
        return tri[i][j] =tri[i][j] + min(mini(tri, i + 1, j, m), mini(tri, i + 1, j + 1, m));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int res;
        c = vector<int> (triangle.size(), -1);
        res = mini(triangle, 0, 0, triangle.size());
        return res;
    }
};