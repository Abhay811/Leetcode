class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, t = INT_MAX, size = prices.size(), s = 0;
        for (int i = 0; i < size; i++) {
            if (prices[i] < t) t = prices[i];
            s = prices[i] - t;
            if (res < s)
                res = s;
        }
        return res;
    }
};