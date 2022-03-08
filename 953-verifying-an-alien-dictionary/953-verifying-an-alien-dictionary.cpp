class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26];
        for (int i = 0; i < 26; i++)
            mp[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mp[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};