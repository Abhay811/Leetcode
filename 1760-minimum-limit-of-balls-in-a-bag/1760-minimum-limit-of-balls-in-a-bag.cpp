class Solution {
public:
    int minimumSize(vector<int>& nums, int m) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2, count = 0;
            for (int a : nums)
                count += (a - 1) / mid;
            if (count > m)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};