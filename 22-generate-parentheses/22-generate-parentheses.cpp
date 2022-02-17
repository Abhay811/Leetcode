class Solution {
    void helper (int n, int lc, int rc, string temp, vector<string>& res) {
        if (lc == n and rc == n) {
            res.emplace_back(temp);
            return;
        }
        if (lc < n) helper(n, lc + 1, rc, temp + "(", res);
        if (rc < lc) helper(n, lc, rc + 1, temp + ")", res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }
};