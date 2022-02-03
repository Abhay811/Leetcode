class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int c = 0;
        unordered_map<int, int> mp;
        
        for (auto &it : nums1)
            for (auto &it2 : nums2)
                mp[it + it2]++;
        for (auto it : nums3)
            for (auto it2 : nums4)
                if (mp.count(0 - it - it2)) c += mp[0 - it - it2];
        return c;
    }
};