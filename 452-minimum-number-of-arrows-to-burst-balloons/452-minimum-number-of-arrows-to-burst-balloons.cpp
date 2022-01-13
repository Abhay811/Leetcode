class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return 1;
        sort(points.begin(), points.end(), comp);
        int arr = 1;
        int prev = points[0][1];
        for (int i = 1; i < size; i++)
        {
            if (points[i][0] <= prev)
                continue;
            arr++;
            prev = points[i][1];
        }
        return arr;
    }
};