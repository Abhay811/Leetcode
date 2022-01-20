class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int t = 1000000000;
        int l = 1;
        while (l <= t)
        {
            int m = (l + t) / 2;
            int c = 0;
            for (int i = 0; i < n; i++)
                c += ceil(1.0 * piles[i] / m);
            if (c > h)
                l = m + 1;
            else
                t = m - 1;
        }
        return l;
    }
};