class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        int windowSum = 0, windowStart = 0;

        double res = INT_MIN;
        for (int windowEnd = 0; windowEnd < n; windowEnd++)
        {
            windowSum += nums[windowEnd];

            if (windowEnd >= k - 1)
            {
                res = max(res, (double)windowSum / k);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return res;
    }
};
