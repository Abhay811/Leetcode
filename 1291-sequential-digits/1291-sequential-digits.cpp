class Solution {
public:
    vector<int> res;
    void dfs(int low, int high, int i, int num)
    {
        if (num >= low and num <= high)
            res.emplace_back(num);
        if (num > high or i > 9)
            return;
        dfs(low, high, i + 1, num * 10 + i);
    }
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; i++)
            dfs(low, high, i, 0);
        sort(res.begin(), res.end());
        return res;
    }
};