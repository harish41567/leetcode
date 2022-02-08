class Solution {
private:
    void combinationSumRec(int ind, int sum, vector<int> &ds, vector<vector<int>> &res, vector<int> &candidates, int target)
    {
        if (sum > target)
            return;
        if (ind == (int)candidates.size())
        {
            if (sum == target)
                res.push_back(ds);
            return;
        }

        // pick
        ds.push_back(candidates[ind]);
        sum += candidates[ind];

        combinationSumRec(ind , sum, ds, res, candidates, target);

        ds.pop_back();
        sum -= candidates[ind];

        // not-pick
        combinationSumRec(ind + 1, sum, ds, res, candidates, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        combinationSumRec(0, 0, ds, res, candidates, target);
        return res;
    }
};