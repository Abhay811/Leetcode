class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.emplace_back(first);
        int i = -1;
        for (auto it : encoded)
            res.emplace_back(res[++i] ^ it);
        return res;
    }
};