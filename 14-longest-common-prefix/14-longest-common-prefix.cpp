class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (auto it : strs)
        {
            string str = "";
            int s1 = res.size(), s2 = it.size();
            int s = min(s1, s2);
            for (int i = 0; i < s; ++i)
                if (res[i] == it[i]) str = str + res[i];
                else break;
            res = str;
        }
        return res;
    }
};