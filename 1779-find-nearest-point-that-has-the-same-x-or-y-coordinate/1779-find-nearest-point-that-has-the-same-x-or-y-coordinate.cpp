class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mx = INT_MAX, ind = 0;
        for (int i = 0, size = points.size(); i < size; ++i)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int s = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (s < mx)
                    mx = s, ind = i;
            }
        }
        return mx == INT_MAX && ind == 0 ? -1 : ind;
    }
};