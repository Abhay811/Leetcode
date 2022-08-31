class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      const int h = heights.size();
        const int w = heights[0].size();
        
        vector<int> grids(w * h, 0);
        
        // trace from Pacific Ocean
        // mask with 0b01
        for (int x = 0; x < w; ++x) maskGrids(heights, grids, 0b01, x, 0, w, h);
        for (int y = 1; y < h; ++y) maskGrids(heights, grids, 0b01, 0, y, w, h);
        
        // trace from Atlantic Ocean
        // mask with 0b10
        for (int x = 0; x < w; ++x)     maskGrids(heights, grids, 0b10, x, h - 1, w, h);
        for (int y = 0; y < h - 1; ++y) maskGrids(heights, grids, 0b10, w - 1, y, w, h);
        
        // get rect that can be traced from both
        // Pacific Ocean and Atlantic Ocean
        //
        // rect masked by both Pacific and Atlantic will be
        // 0b01 | 0b10 => 0b11
        vector<vector<int>> result;
        
        int i = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grids[i++] != 0b11) continue;
                result.push_back({ y, x });
            }
        }
        
        return result;
    }
    
    void maskGrids(vector<vector<int>> &heights, vector<int> &grids, int mask, int x, int y, int w, int h) {
        // mark current grid as visited
        grids[y * w + x] |= mask;
        
        // visit next
        nextGrid(heights, grids, mask, x, y, x - 1, y + 0, w, h);
        nextGrid(heights, grids, mask, x, y, x + 1, y + 0, w, h);
        nextGrid(heights, grids, mask, x, y, x + 0, y - 1, w, h);
        nextGrid(heights, grids, mask, x, y, x + 0, y + 1, w, h);
    }
    
    void nextGrid(
        vector<vector<int>> &heights,
        vector<int> &grids,
        int mask,
        int cur_x, int cur_y,
        int next_x, int next_y,
        int w, int h) {
        
        // check if out-of-bound
        if (!isValidGrid(next_x, next_y, w, h)) return;
        
        // check if next grid is already visited
        const int next_grid = getPixel(grids, next_x, next_y, w);
        if ((next_grid & mask) != 0) return;
        
        // check if water can flow from next to cur,
        // as we trace from ocean to mountain
        //
        // water can only flow from place higher or same level
        const int cur_height = heights[cur_y][cur_x];
        const int next_height = heights[next_y][next_x];
        
        if (cur_height > next_height) return;
        
        // dfs
        maskGrids(heights, grids, mask, next_x, next_y, w, h);
    }
    
    bool isValidGrid(int x, int y, int w, int h) {
        return x >= 0 && x < w && y >= 0 && y < h;
    }
    
    int getPixel(vector<int> &grids, int x, int y, int w) {
        return grids[y * w + x];  
    }
};