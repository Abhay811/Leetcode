class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j)
        {
            int t = min(height[i], height[j]);
            res = max (res, (j - i) * t);
            while (height[i] <= t && i < j) i++;
            while (height[j] <= t && i < j) j--;
        }
        return res;
    }
};