class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>:: iterator it;
        it = unique(nums.begin(), nums.end());
        return distance(nums.begin(), it);
    }
};