class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        string  t = "";
        for (int i = 0; i < size; i++)
        {
            if (isalnum(s[i])) t += tolower(s[i]);
        }
        int len = t.size();
        if (len == 0) return true;
        for (int i = 0; i < len / 2; i++)
            if (t[i] != t[len - 1 - i]) return false;
        return true;
    }
};