class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN, ar = 0, top = 0, i = 0, size = heights.size();
        stack<int> s;
        while (i < size) {
            if (s.empty() || heights[s.top()] <= heights[i]) s.push(i++);
            else {
                top = s.top(); s.pop();
                ar = heights[top] * (s.empty() ? i : i - s.top() - 1);
                res = max (res, ar);
            }
        }
        while (!s.empty()) {
            top = s.top(); s.pop();
            ar = heights[top] * (s.empty() ? i : i - s.top() - 1);
            res = max (res, ar);
        }
        return res;
    }
};