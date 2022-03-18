class Solution {
private:
    int partition(int ind, int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (target == 0)
            return 1;
        if (ind == 0)
        {
            if (nums[ind] == target)
                return 1;
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        int pick = 0;
        if (target >= nums[ind])
            pick = partition(ind - 1, target - nums[ind], nums, dp);

        int nonPick = partition(ind - 1, target, nums, dp);

        return dp[ind][target] = pick | nonPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (auto it : nums)
            sum += it;
        if (sum % 2 == 1)
            return false;

        vector<vector<int>> dp(n, vector<int> (sum / 2 + 1, -1));
        return partition(n - 1, sum / 2, nums, dp) == 1 ? true : false;
    }
};
