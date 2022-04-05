class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60);
        int res = 0;
        for (auto it : time)
            res += v[(60 - it % 60) % 60], v[it % 60] += 1;
        return res;
    }
};