class Solution {
public:
    int titleToNumber(string s) {
        int n = 0, i = 0;
        reverse(s.begin(), s.end());
        while (i < s.size())
        {
            n += (s[i] - 'A' + 1) * pow(26, i);
            i++;
        }
        return n;
    }
};