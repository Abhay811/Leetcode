class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; i++)
        {
            int ind1 = i - 1, ind2 = i - 2;
            cost[i] += min(cost[ind1], cost[ind2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};