class Solution {
public:
    int maxProfitK(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        
        for(int i=1;i<=k;i++)
        {
            int maxSoFar=INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxSoFar=max(maxSoFar,(-prices[j-1] + dp[i-1][j-1]));
                
                dp[i][j]=max(dp[i][j-1], prices[j] + maxSoFar);
            }
        }
        
        return dp[k][n-1];
    }
    
    int maxProfit(vector<int>& prices) {
        return maxProfitK(2, prices);
    }
};