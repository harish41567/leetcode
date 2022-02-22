class Solution {
private:
    int minTotal(vector<vector<int>>& triangle, int rows, int columns, int i, int j, vector<vector<int>>& dp)
    {
        if (i == rows - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + minTotal(triangle, rows, columns, i + 1, j, dp);
        int diagonal = triangle[i][j] + minTotal(triangle, rows, columns, i + 1, j + 1, dp);

        return dp[i][j] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();

        vector<vector<int>> dp(m , vector<int>(n, -1));
        return minTotal(triangle, m, n, 0, 0, dp);
    }
};