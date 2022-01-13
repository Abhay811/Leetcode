class Solution {
   
public:
    int search(vector<int>& nums, int target) {
        
        int r = nums.size() - 1;
        int l = 0;
        while (l <= r)
        {
            int m = l + (r - l)/ 2;
            if (nums[m] == target)
                return m;
            if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};