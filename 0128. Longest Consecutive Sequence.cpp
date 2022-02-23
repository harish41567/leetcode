class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int res = 0;
        unordered_set<int> s;

        for (auto it : nums)
            s.insert(it);

        for (auto it : nums)
        {
            if (s.find(it - 1) == s.end())
            {
                int i = 1, ans = 1;
                while (s.find(it + i) != s.end())
                {
                    ans++;
                    i++;
                }
                res = max(res, ans);
            }
        }

        return res;
    }
};