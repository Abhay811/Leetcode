class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& time) {
        sort(time.begin(), time.end());
        int a = time[0][0], b = time[0][1];
        int res = 1;
        for (int i = 1, size = time.size(); i < size; ++i) {
            if (time[i][0] > a && time[i][1] > b) ++res;
            if (time[i][1] > b)
                a = time[i][0], b = time[i][1];
        }
        return res;
    }
};