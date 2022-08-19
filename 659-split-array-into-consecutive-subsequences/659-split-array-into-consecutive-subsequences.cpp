class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp, last;
        for (auto it : nums)
            mp[it]++;
        
        for (auto it : nums)
        {
            if (mp[it] == 0) continue;
            mp[it]--;
            if (last[it - 1] > 0)
                last[it - 1]--, last[it]++;
            else if (mp[it + 1] > 0 && mp[it + 2] > 0)
                mp[it + 1]--, mp[it + 2]--, last[it + 2]++;
            else 
                return false;
        }
        return true;
        
    }
};