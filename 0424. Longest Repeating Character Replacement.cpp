class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0, maxRepeating = 0;
        int windowStart = 0;
        vector<int> map(26, 0);

        for (int windowEnd = 0; windowEnd < n; windowEnd++)
        {
            map[s[windowEnd] - 'A']++;
            maxRepeating = max(maxRepeating, map[s[windowEnd] - 'A']);

            if (windowEnd - windowStart + 1 - maxRepeating > k)
            {
                map[s[windowStart] - 'A']--;
                windowStart++;
            }

            res = max(res, windowEnd - windowStart + 1);
        }

        return res;
    }
};
