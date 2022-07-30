class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> vec(1), res;
        int prev = 0;
        for (auto it : arr)
            vec.emplace_back(it ^ vec.back());
        vec.erase(vec.begin());        
        for (auto it : queries)
            if (it[0] == 0) res.emplace_back(vec[it[1]]);
            else res.emplace_back(vec[it[0] - 1] ^ vec[it[1]]);
        return res;
        
    }
};