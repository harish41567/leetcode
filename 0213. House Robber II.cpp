class Solution {
private:
    int robHelper(int start, int end, vector<int> &nums)
    {
        int second = nums[start];
        int first = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++)
        {
            int current = max(first, second + nums[i]);
            second = first;
            first = current;
        }

        return first;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        return max(robHelper(0, n - 2, nums), robHelper(1, n - 1, nums));
    }
};
