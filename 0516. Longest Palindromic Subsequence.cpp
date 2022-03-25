class Solution {
private:
    int LPS(int start, int end, string &s, vector<vector<int>> &dp)
    {
        if (start == end)
            return 1;
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];

        if (s[start] == s[end])
            return dp[start][end] = 2 + LPS(start + 1, end - 1, s, dp);

        return dp[start][end] = max(LPS(start + 1, end, s, dp), LPS(start, end - 1, s, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return LPS(0, n - 1, s, dp);
    }
};
