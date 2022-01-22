class Solution {
    int CHARS = 256;
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0, i = 0;
        vector<int> ind(CHARS, -1);
        for (int j = 0; j < n; j++)
        {
            i = max(i, ind[s[j]] + 1);
            res = max (res, j - i + 1);
            ind[s[j]] = j;
        }
        return res;
    }
};