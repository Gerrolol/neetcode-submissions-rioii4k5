class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == INT_MAX) {
                    int minPath = bfs(grid, i, j);
                    grid[i][j] = minPath;
                }
            }
        }
    }

    int bfs(vector<vector<int>>& grid, int start_i, int start_j) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({start_i, start_j});
        visited[start_i][start_j] = true;
        int depth = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (grid[x][y] == 0) {
                    return depth;
                }
                for (auto& dir : dirs) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && grid[new_x][new_y] != -1) {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                }
            }
            depth++;
        }
        return INT_MAX;
    }
};

