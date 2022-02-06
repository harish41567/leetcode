class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n <= 3)
            return ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 4; i++)
        {
            for (int j = i + 1; j <= n - 3; j++)
            {
                int to_find = target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] == to_find)
                    {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
                        res.push_back(nums[left]);
                        res.push_back(nums[right]);
                        ans.push_back(res);

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;

                        while (left < right && nums[right - 1] == nums[right])
                            right--;
                        right--;
                    }
                    else if (nums[left] + nums[right] < to_find)
                        left++;
                    else
                        right--;
                }
                while (j <= n - 3 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i <= n - 4 && nums[i] == nums[i + 1])
                i++;

        }

        return ans;

    }
};