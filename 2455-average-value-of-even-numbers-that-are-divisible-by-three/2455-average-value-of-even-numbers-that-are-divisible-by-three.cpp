class Solution {
public:
    int averageValue(vector<int>& nums) {
        int c = 0, sum = 0;
        for (auto it : nums)
            if (it & 1) continue;
            else if (it % 6 == 0) sum += it, c++;
        return c == 0 ? 0 : sum / c;
    }
};