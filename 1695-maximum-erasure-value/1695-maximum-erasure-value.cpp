class Solution {
public:
     int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        int l = 0, sum = 0, ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            int x = nums[r];
            if (m.find(x) != m.end()) {
                int index = m[x];
                while (l <= index) {
                    m.erase(nums[l]);
                    sum -= nums[l];
                    l += 1;
                }
            }
            m[x] = r;
            sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};