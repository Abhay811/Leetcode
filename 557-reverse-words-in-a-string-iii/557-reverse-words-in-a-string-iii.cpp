class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int l = 0, r;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == ' ')
                reverse(s.begin() + l, s.begin() + i), l = i + 1;
        }
        reverse(s.begin()+l, s.end());
        return s;
    }
};