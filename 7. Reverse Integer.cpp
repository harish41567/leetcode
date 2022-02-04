class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        int y = x;
        if (y < 0)
            y = -y;

        int ans = 0;
        while (y)
        {
            int ld = y % 10;

            if (ans > (INT_MAX - ld) / 10)
                return 0;
            ans = ans * 10 + ld;
            y = y / 10;

        }

        if (x < 0)
            return -ans;
        return ans;
    }
};