class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> c(26);
        for (auto ch : magazine)
            c[ch - 'a']++;
        for (auto ch : ransomNote)
            if(c[ch - 'a']-- <= 0)
                return false;
        return true;
    }
};