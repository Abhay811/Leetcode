class Solution {
public:
        int n = 0;
    int m = 0;
    // mask, gcd;
    vector<pair<int, int>> g;
    vector<int> dp;
    int gcd(int a, int b)
    {
        if (b < a) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    int bitset(int mask)
    {
        int cnt = 0;
        while (mask != 0)
        {
            mask = mask &(mask - 1);
            cnt++;
        }
        return cnt;
    }
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        m = nums.size();
        n = m / 2;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                int mask = 0;
                mask = mask | (1 << i);
                mask = mask | (1 << j);
                g.push_back({mask,  gcd(nums[i], nums[j])});
            }
        }
        int l = 1 << m;
        dp = vector<int> (l);
        dp[0] = 0;
        int mask = 0;
        for (mask = 0; mask < l; mask++)
        {
            int cnt = bitset(mask);
            if (cnt % 2 == 1) continue;
            cnt = cnt/2;
            int ans = 0;
            for (auto& p : g)
            {
                int mk = p.first;
                if ((mk & mask)== mk)
                {
                    int pre = mask - mk;
                    ans = max(ans, p.second * cnt + dp[pre]);
                }
            }
            dp[mask] = ans;
        }
        return dp[l - 1];
    }
};