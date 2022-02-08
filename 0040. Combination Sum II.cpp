class Solution {
private:
    void combinations(int index, vector<int>& candidates, int target, vector<int> &res, vector<vector<int>> &ans)
    {
        if (index == (int)candidates.size() || target == 0)
        {
            if (target == 0)
                ans.push_back(res);

            return;
        }

        for (int i = index; i < (int)candidates.size(); i++)
        {
            if (i != index && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] <= target)
            {
                res.push_back(candidates[i]);
                combinations(i + 1, candidates, target - candidates[i], res, ans);
                res.pop_back();
            }
            else
                break;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());

        combinations(0, candidates, target, res, ans);
        return ans;
    }
};