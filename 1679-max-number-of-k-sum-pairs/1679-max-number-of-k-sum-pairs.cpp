class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int c = 0;
        for (auto it : nums)
        {
            int r = k - it;
            if (ump[r] > 0) c++, ump[r]--;
            else ump[it]++;
        }
        return c;
    }
};