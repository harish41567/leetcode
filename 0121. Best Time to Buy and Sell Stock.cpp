class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        int res = 0;
        int prev = 0; // buy and sell on the first day


        for (int i = 1; i < n; i++) 
        {
            int curr = max(prev + (prices[i] - prices[i - 1]), 0); // either extend previous profit or start from the current day
            prev = curr;
            res = max(res, curr);
        }

        return res;

//         int n=prices.size();
//         vector<int> dp(n);

//         int res=0;
//         dp[0]=0; // buy and sell on the first day

//         // dp[i] is the profit if we sell the stock on the ith day
//         for(int i=1;i<n;i++){
//             dp[i]=max(dp[i-1]+(prices[i]-prices[i-1]), 0); // either extend previous profit or start from the current day
//             res=max(res,dp[i]);
//         }

//         return res;
    }
};
