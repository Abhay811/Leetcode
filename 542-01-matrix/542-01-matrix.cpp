class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
		
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++)
            for(int j=0;j<n;j++)
                if(mat[i][j] == 0)
                    q.push({{i, j}, 0});
		
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
		
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            mat[it.first.first][it.first.second] = -1;
            ans[it.first.first][it.first.second] = min(ans[it.first.first][it.first.second], it.second);
			
            for(int i = 0; i < 4; i++){
            int x = dx[i] + it.first.first, y = dy[i] + it.first.second;
                if(x < 0 || y < 0|| x >= m|| y >= n) continue;
                if(mat[x][y] < 0) continue;
                q.push({{x, y}, it.second + 1});
            }
        }
        return ans;
    }
};