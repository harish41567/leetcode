class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (abs(nums[i] - nums[j]) == k)
                    cnt++;
            }
        }

        return cnt;
    }
};
