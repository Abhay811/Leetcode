class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        for (int i = s.length() - 1; i >= 0; --i)
            if (s[i] == ' ' && c != 0)
                return c;
            else if (isalpha(s[i])) c++;
        return c;
    }
};