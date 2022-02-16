class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) { 
        for (int i = 0, n = matrix.size(); i < n; ++i)
        {
            set<int> si, si2;
            for (int j = 0; j < n; ++j)
            {
                if (si.count(matrix[i][j]))
                    return false;
                else si.insert(matrix[i][j]);
                if (si2.count(matrix[j][i])) return false;
                else si2.insert(matrix[j][i]);
            }
        }
        return true;
    }
};