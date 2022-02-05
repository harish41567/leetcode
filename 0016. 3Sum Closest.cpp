class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0, absDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum ) < absDiff)
                {
                    absDiff = abs(target - sum );
                    res = sum;
                }

                if (sum == target)
                    return target;
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};