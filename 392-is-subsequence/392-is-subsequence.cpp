class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!s.size()) return true;
        if (!t.size()) return false;
        for (int i = 0; i <= t.size() - s.size(); ++i)
            if (s[0] == t[i])
                return isSubsequence(s.substr(1, s.size() - 1), t.substr(i + 1, t.size() - 1));
        return false;
    }
};