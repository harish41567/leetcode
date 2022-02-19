class Solution {
private:
    void subsets(int index, vector<int> &nums, vector<int> &res, vector<vector<int>> &ans)
    {
        ans.push_back(res);

        for (int i = index; i < (int)nums.size(); i++)
        {
            if (i != index && nums[i - 1] == nums[i])
                continue;

            res.push_back(nums[i]);
            subsets(i + 1, nums, res, ans);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());

        subsets(0, nums, res, ans);
        return ans;
    }
};