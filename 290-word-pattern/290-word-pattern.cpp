class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pm;
        unordered_map<string, int> sm;
        istringstream in(s);
        string word;
        int i = 0, n = pattern.size();
        for (word; in >> word; i++) {
            if (i == n || pm[pattern[i]] != sm[word]) return false;
            pm[pattern[i]] = sm[word] = i + 1;
        }
        return i == n;
    }
};