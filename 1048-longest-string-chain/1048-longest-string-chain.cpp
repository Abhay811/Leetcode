class Solution {
    static bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort (words.begin(), words.end(), cmp);
        unordered_map<string, int> ump;
        int res = 0;
        for (auto w : words) {
            for (int i = 0; i < w.length(); ++i)
            {
                string pre = w.substr(0, i) + w.substr(i + 1);
                ump[w] = max(ump[w], ump.find(pre) == ump.end() ? 1 : ump[pre] + 1);
            }
            res = max(res, ump[w]);
        }
        return res;
    }
};