class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        int size = s.size();
        int ind = size;
        for (int i = 0; i < size; i++)
            mp[s[i]].first++, mp[s[i]].second = i;
        for (auto [c, p] : mp)
            if (p.first == 1)
                ind = min(ind, p.second);
        
        return ind == size ? -1 : ind;
    }
};