class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int, int> mp;
        for (auto it : arr) mp[it]++;
        vector<int> count(size + 1);
        
        for (auto [val, freq] : mp) count[freq]++;
        
        int res = 0, rem = 0, half = size/ 2, freq = size;
        while(rem < half)
        {
            res++;
            while (count[freq] == 0) --freq;
            rem += freq;
            count[freq]--;
        }
        return res;
    }
};