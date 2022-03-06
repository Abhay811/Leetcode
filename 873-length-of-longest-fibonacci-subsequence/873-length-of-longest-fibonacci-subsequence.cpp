class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> m;
        int n = arr.size(), res = 0;
        vector<vector<int>> dp(n, vector<int> (n));
        for (int j = 0; j < n; ++j) {
            m[arr[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(arr[j] - arr[i]) == m.end() ? -1 : m[arr[j] - arr[i]];
                dp[i][j] = (arr[j] - arr[i] < arr[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};