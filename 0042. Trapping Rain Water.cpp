class Solution {
public:
    int trap(vector<int>& height) {

        int i, ans = 0, n = height.size();
        vector<int>l(n), r(n);

        if (n == 0)
            return 0;

        l[0] = height[0];
        for (i = 1; i < n; i++)
            l[i] = max(l[i - 1], height[i]);

        r[n - 1] = height[n - 1];
        for (i = n - 2; i >= 0; i--)
            r[i] = max(r[i + 1], height[i]);

        for (i = 0; i < n; i++)
            ans += (min(l[i], r[i]) - height[i]);

        return ans;
    }
};