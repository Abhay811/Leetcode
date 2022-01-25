class Solution {
public:
    void solve (string s, int id, vector<string> &res, string temp)
    {
        if (id >= s.size()) {
            res.emplace_back(temp);
            return;
        }
        solve(s, id + 1, res, temp + s[id]);
        if (!(s[id] >= '0' && s[id] <= '9')) {
            if (islower(s[id])) 
                temp += toupper(s[id]);
            else
                temp += tolower(s[id]);
            solve(s, id + 1, res, temp);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int id = 0;
        string temp;
        solve(s, id, res, temp);
        return res;
    }
};