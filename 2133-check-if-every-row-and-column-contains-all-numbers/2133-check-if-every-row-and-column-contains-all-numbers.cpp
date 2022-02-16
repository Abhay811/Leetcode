class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {        
        for (int i = 0, n = matrix.size(); i < n; ++i)
        {
            set<int> si;
            for (int j = 0; j < n; ++j)
                if (si.count(matrix[i][j]))
                    return false;
                else si.insert(matrix[i][j]);
            si.clear();
            for (int j = 0; j < n; ++j)
                if (si.count(matrix[j][i]))
                    return false;
                else si.insert(matrix[j][i]);
        }
        return true;
    }
};