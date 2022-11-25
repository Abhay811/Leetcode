class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j, string &word) {
        if (!word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char letter = board[i][j];
        board[i][j] = '*';
        string w = word.substr(1);
        bool res = dfs(board, i - 1, j, w) || dfs(board, i + 1, j, w) || dfs(board, i, j -1, w) || dfs(board, i, j + 1, w);
        board[i][j] = letter;
        return res;
    }
};