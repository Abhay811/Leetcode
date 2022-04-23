class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, amount + 1);
        res[0] = 0;
        for (auto it : coins)
            for (int i = it; i <= amount; ++i)
                res[i] = min(res[i], res[i - it] + 1);
        return res[amount] > amount ? -1 : res[amount];
    }
    
};