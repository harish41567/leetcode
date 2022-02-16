class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int>m;
        int res = 0, presum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                presum += -1;
            else
                presum += nums[i];

            if (presum == 0)
                res = i + 1;

            if (m.find(presum) == m.end())
                m.insert({presum, i});
            else
                res = max(res, i - m[presum]);
        }
        return res;
    }
};
