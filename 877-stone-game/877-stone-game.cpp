class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int o = 0, e = 0;
        for (int i = 0, n = piles.size(); i < n; ++i)
            if (i & 1) o += piles[i];
            else e += piles[i];
        return 1;
    }
};