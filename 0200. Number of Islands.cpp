class Solution {
private:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || vis[i][j] == true || grid[i][j] == '0')
            return;

        vis[i][j] = true;
        dfs(i - 1, j, vis, grid);
        dfs(i, j + 1, vis, grid);
        dfs(i + 1, j, vis, grid);
        dfs(i, j - 1, vis, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n, false));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return ans;
    }
};
