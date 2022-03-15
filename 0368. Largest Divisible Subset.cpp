class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int res = 0, index = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[i] > res) {
                res = dp[i];
                index = i;
            }
        }

        vector<int> v;
        while (index != -1) {
            v.push_back(nums[index]);
            index = pre[index];
        }

        return v;
    }
};
