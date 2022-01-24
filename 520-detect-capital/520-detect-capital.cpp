class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.length();
        int c = 0, t = 0;
        for (int i = 0; i < size; i++)
        {
            if (isupper(word[i]))
                c++;
            if (islower(word[i]))
                t++;
        }
        if (c == size || t == size)
            return true;
        else if (isupper(word[0]) && t + 1 == size)
            return true;
        return false;
    }
};