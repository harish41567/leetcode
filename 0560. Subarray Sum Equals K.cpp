class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int res = 0;
        int preSum = 0;
        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            if (preSum == k)
                res++;
            if (mp.find(preSum - k) != mp.end())
                res += mp[preSum - k];

            if (mp.find(preSum) != mp.end())
                mp[preSum]++;
            else
                mp[preSum] = 1;
        }

        return res;
    }
};
