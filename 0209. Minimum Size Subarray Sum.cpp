class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int windowStart = 0;
        int res = INT_MAX;

        for (int windowEnd = 0; windowEnd < n; windowEnd++)
        {
            sum += nums[windowEnd];

            while (sum >= target)
            {
                res = min(res, windowEnd - windowStart + 1);
                sum -= nums[windowStart];
                windowStart++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
