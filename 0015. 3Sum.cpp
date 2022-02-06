class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        if (nums.size() < 3)
            return {};

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0 || (i > 0 && nums[i] == nums[i - 1]))
                continue;

            int j = i + 1, k = n - 1;

            while (j < k)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    j++;
                else if (k < n - 1 && nums[k] == nums[k + 1])
                    k--;
                else if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
