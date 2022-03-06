class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int i = 0;
        // vector<int> res;
        // sort(nums.begin(), nums.end());
        // for (int j = 0; j < nums.size(); ++j)
        //     if (target == nums[j])
        //         res.emplace_back(j);
        // return res;
        
        //counting sort
         int cnt = 0, rank = 0;
        for (int n : nums) 
        {
            cnt += n == target;
            rank += n < target;
        }
        vector<int> res;
        while (cnt--) res.emplace_back(rank++);
        return res;
    }
};