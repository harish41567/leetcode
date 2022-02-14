class Solution {
public:
    int mySqrt(int x) {
        int l = 1, h = x, ans = 0;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (mid == (x / mid))
                return mid;
            else if (mid > (x / mid))
                h = mid - 1;
            else {
                l = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};