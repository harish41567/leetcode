class Solution {
private:
    int fibonacci(int n, vector<int>& dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    }

public:
    int fib(int n)
    {
        // vector<int> dp(n+1, -1);
        // return fibonacci(n, dp);
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
