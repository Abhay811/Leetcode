class Solution {

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        cout << n;
        if (n == 1)
            return;
        if (n == k)
            return;
        else if (k > n)
            k = k % n;
        cout << k;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};