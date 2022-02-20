class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int resl = 0, l, r, t;
        for (int i = 0; i < n; ++i) {
            l = r = i;
            while (l >= 0 and r < n and s[l] == s[r]) {
                t = r - l + 1;
                if(t > resl)
                    res = s.substr(l, t), resl =t;
                --l, ++r;
            }
            l = i;
            r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                t = r - l + 1;
                if(t > resl)
                    res = s.substr(l, t), resl = t;
                --l, ++r;
            }
        }
        return res;
    }
};