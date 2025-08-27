class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dirs[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}}; // down-right, down-left, up-left, up-right
        int turn[4] = {1, 2, 3, 0}; // clockwise turn mapping
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        maxLen = max(maxLen, explore(grid, i, j, d, dirs, turn, 0, false));
                    }
                }
            }
        }
        return maxLen;
    }
    
private:
    int explore(vector<vector<int>>& grid, int r, int c, int dir, int dirs[4][2], int turn[4], int pos, bool turned) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
        
        int expected = pos == 0 ? 1 : (pos % 2 == 1 ? 2 : 0);
        if (grid[r][c] != expected) return 0;
        
        int result = 1;
        int nr = r + dirs[dir][0], nc = c + dirs[dir][1];
        
        // Continue straight
        result = max(result, 1 + explore(grid, nr, nc, dir, dirs, turn, pos + 1, turned));
        
        // Try clockwise turn if not turned yet
        if (!turned) {
            int newDir = turn[dir];
            nr = r + dirs[newDir][0];
            nc = c + dirs[newDir][1];
            result = max(result, 1 + explore(grid, nr, nc, newDir, dirs, turn, pos + 1, true));
        }
        
        return result;
    }
};