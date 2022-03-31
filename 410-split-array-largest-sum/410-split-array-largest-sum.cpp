class Solution {
public:
    bool do_able(const vector<int> &nums, int cuts, long long m) {
        int acc = 0;
        for (auto num : nums)
        {
            if (num > m) return false;
            else if (acc + num <= m) acc += num;
            else
            {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;
        for (auto num : nums)
        {
            l = max(l, (long long)num);
            r += num;
        }
        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            if (do_able(nums, m - 1, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};