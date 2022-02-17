class Solution {
    void combination(vector<int> &cand, int target, vector<int> comb, int s, int ind, vector<vector<int>> &res) {
        if (s > target) return;
        if (s == target) {
            res.emplace_back(comb);
            return;
        }
        for (int i = ind, size = cand.size(); i < size; ++i) {
            comb.emplace_back(cand[i]);
            s += cand[i];
            combination(cand, target, comb, s, i, res);
            comb.pop_back();
            s -= cand[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        combination(candidates, target, comb, 0, 0, res);
        return res;
    }
};