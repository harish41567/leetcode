class Solution {
private:
    void permute(int ind, int size, vector<vector<int>> &res, vector<int> &nums)
    {
        if (ind == size)
        {
            res.push_back(nums);
            return;
        }

        for (int i = ind; i < size; i++)
        {
            swap(nums[ind], nums[i]);
            permute(ind + 1, size, res, nums);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        permute(0, n, res, nums);

        return res;
    }
};