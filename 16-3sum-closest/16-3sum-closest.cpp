class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int cs = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0, size = nums.size(); i < size - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = size - 1;
            while (j < k)
            {
                int csum = nums[i] + nums[j] + nums[k];
                if (csum == target) return csum;
                if (abs(target - csum) < abs(target - cs))
                    cs = csum;
                if (csum > target)
                    --k;
                else ++j;
            }
        }
        return cs;
    }
};